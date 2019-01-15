#include "MotorDriver.h"

#include "Interpolate.h"


#define MAX_PWM_PINS 2

// Keeps track of whether the library has been enabled or not.
static BIT pwmStartedFlag = 0;

// Associates external channel number (the number picked by the user) to the
// internal channel number.
static uint8 XDATA pwmAssignment[MAX_PWM_PINS];

/*! This struct is part of the internal implementation of the servo library.
 *  See servo.h. */
struct PWM_DATA
{
    uint16 target;       /*!< Chosen duty cycle, measured in ticks. */
    uint16 targetReg;  /*!< The value to be written to the duty cycle register. */
};

// Array of 
static volatile struct PWM_DATA XDATA pwmData[MAX_PWM_PINS];

// Bitmasks for keeping track of which pins are being used as servos.
// A 1 bit indicates that the pin is a servo pulse output pin.
// A 0 bit indicates that the pin will be used for something else and
// this library should not touch it.
static volatile uint8 pwmPinsOnPort0;
static volatile uint8 pwmPinsOnPort1;


/// speed ranges from -127 to 127.
void setMotorSpeed(MOTOR *motor, int8 speed){
    // T1CC0 is the timer 1 period in ticks
    uint16 top = T1CC0;
    
    // New compare threshold
    uint16 ticks_on = 0;
    
    if( speed > 0 ){
        ticks_on = interpolateU(speed, 0, DRIVE_SPEED_MAX, 0, top);

        // Set direction1 high, direction2 low
        setDigitalOutput(motor->direction1, HIGH);
        setDigitalOutput(motor->direction2, LOW);
    }else if(speed < 0){
        ticks_on = interpolateU(speed, 0, DRIVE_SPEED_MIN, 0, top);

        // Set direction1 low, direction2 high low
        setDigitalOutput(motor->direction1, LOW);
        setDigitalOutput(motor->direction2, HIGH);
    }else{
        // brake
        ticks_on = 0;
        
        if(motor->direction2){
            // There are two direction pins - so set both to same value
            setDigitalOutput(motor->direction1, LOW);
            setDigitalOutput(motor->direction2, LOW);
        }else{
            // Only has one direction pin
            // Set direction1 to an input with no pullup ie disconnect
            setDigitalOutput(motor->direction1, LOW);
        }
    }

    // Change the duty cycle
    pwmSetTargetHighRes(motor->pwmpin, ticks_on);
}

void pwmSetTarget(uint8 pinNum, uint16 targetMicroseconds)
{
    // Convert the units of target from microseconds to timer ticks.
    pwmSetTargetHighRes(pinNum, targetMicroseconds * TICKS_PER_MICROSECOND);
}

void pwmSetTargetHighRes(uint8 pinNum, uint16 target)
{
    // TODO: return here if "target" is out of the valid range
        
    if (pwmStartedFlag) {
        // NOTE: T1CCx is buffered, so these commands
        // don't take effect until the next timer period.
        
        /// Because we are using Modulo mode, pins P0_2 and P1_2 are not usable for PWM
        switch(pinNum) {
        case 3:
            P0SEL |= pwmPinsOnPort0;
            T1CC1 = target;  break;
        case 11:
            P1SEL |= pwmPinsOnPort1;
            T1CC1 = target;  break;

        case 4:
            P0SEL |= pwmPinsOnPort0;
            T1CC2 = target; break;
        case 10:
            P1SEL |= pwmPinsOnPort1;
            T1CC2 = target; break;
        }
    }
}

void pwmStart(uint8 XDATA * pins, uint8 numPins, uint16 frequency)
{
    uint8 i;

    if (pwmStartedFlag)
    {
        pwmStop();
    }

    /// Configure the pins and initialize the internal data structures. ///

    // The user passes a null argument for pins, then don't reinitialize the pins.
    // This allows us to temporarily start and stop the servos without losing track
    // of the old speeds, targets, and positions.
    if (pins != 0)
    {
        pwmPinsOnPort0 = pwmPinsOnPort1 = 0;
        for (i = 0; i < MAX_PWM_PINS; i++)
        {
            // pwmData[i].target = 0;
            // pwmData[i].targetReg = 0;
            
            if (i < numPins)
            {
                switch(pins[i]) {
                case 3: P0_3 = 0; pwmPinsOnPort0 |= (1<<3); break;
                case 4: P0_4 = 0; pwmPinsOnPort0 |= (1<<4); break;
                case 11: P1_1 = 0; pwmPinsOnPort1 |= (1<<1); break;
                case 10: P1_0 = 0; pwmPinsOnPort1 |= (1<<0); break;
                }
            }
        }

        if (pwmPinsOnPort0)
        {
            // Set P2DIR.PRIP0[1:0] to 11 (Timer 1 channel 2 - USART0).
            // (Pololu) I'm not sure why this is necessary, but if it is not set then
            // Timer 1 can not control P0_4, even if no other peripherals on Port 0 are enabled.
            P2DIR |= 0b11000000;
        }
    }
    
    /// Check that valid pin combination was chosen ///
    if (pwmPinsOnPort0 && pwmPinsOnPort1) {
        // invalid configuration for PWM
        return;
    }
    else if (pwmPinsOnPort1) {
        PERCFG |= (1<<6);  // PERCFG.T1CFG = 1:  Move Timer 1 to Alt. 2 location (P1_2, P1_1, P1_0)

        // Set the pins being used to be general-purpose outputs driving low for now.
        P0SEL &= ~pwmPinsOnPort0; // set as "general purpose IO"
        P0DIR |= pwmPinsOnPort0; // set as "output"
    }
    else if (pwmPinsOnPort0) {
        PERCFG &= ~(1<<6);  // PERCFG.T1CFG = 0:  Move Timer 1 to Alt. 1 location (P0_2, P0_3, P0_4)

        // Set the pins being used to be general-purpose outputs driving low for now.
        P1SEL &= ~pwmPinsOnPort1; // set as "general purpose IO"
        P1DIR |= pwmPinsOnPort1; // set as "output"
    }
    // else {
        
    // }
    
    /// Configure Timer 1 ///

    // Turn off the timer and reset the counters.
    T1CTL = 0; // control register; 
    T1CNTL = 0;  // counter register; resets high and low bytes that store the time

    // Configure Timer 1 Channels 0-2 to be in compare mode.  Clear output on compare-up, set on 0.
    // T1CCTL0 = T1CCTL1 = T1CCTL2 = 0b00011100;
    T1CCTL1 = T1CCTL2 = 0b00100100;

    // Turn off all the pulses at first.
    // i.e.: T1CCn = 0 -> immediate compare-up -> clear outputs
    T1CC1 = T1CC2 = 0x0000;

    // Timer 1: Start modulo mode, counting from 0x0000 to T1CC0.
    T1CTL = 0b00000010; // control register;
    
    // Convert the frequency to T1CC0 by the equation:
    //    T1CC0=2.4*10^4/(frequency/1000)
    T1CC0 = 24000 / (frequency / 1000);
    
    // // Set the Timer 1 interrupt priority to 2, the second highest.
    // IP0 &= ~(1<<1);
    // IP1 |= (1<<1);
    // T1IE = 1; // Enable the Timer 1 interrupt.
    // EA = 1;   // Enable interrupts in general.

    pwmStartedFlag = 1;
}

void pwmStop(void)
{
    if (!pwmStartedFlag)
    {
        // The servos have already been stopped.
        return;
    }

    // T1IE = 0;

    // Wait for the timer to overflow.
    while(!T1IF){};

    // Assuming that there were fewer than (2730 - MAX_SERVO_TARGET_MICROSECONDS) worth of
    // interrupts, the time when T1IF was read as true and now, the timer has just
    // overflowed and the next servo pulses have not started yet.
    // Make the pins revert to GPIO outputs driving low:
    P0SEL &= ~pwmPinsOnPort0;
    P1SEL &= ~pwmPinsOnPort1;

    // Turn off Timer 1.
    T1CTL = 0;

    pwmStartedFlag = 0;
}
