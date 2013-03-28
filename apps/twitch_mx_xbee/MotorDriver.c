//#include "../motorPWM.h"
#include "MotorDriver.h"
//#include "../timer.h"

#include "Interpolate.h"


#define MAX_PWM_PINS 6

// Keeps track of whether the library has been enabled or not.
static BIT pwmStartedFlag = 0;

// Keeps track of whether there are motors moving or not (position != target).
// This is updated in the ISR.
static volatile BIT motorsMovingFlag = 0;

volatile uint8 DATA pwmCounter = 0;

// Associates external channel number (the number picked by the user) to the
// internal channel number.
static uint8 XDATA pwmAssignment[3]; //MAX_PWM_PINS];

/*! This struct is part of the internal implementation of the servo library.
 *  See servo.h. */
struct PWM_DATA
{
    uint16 target;       /*!< Target position, measured in ticks. */
    uint16 position;     /*!< Current position, measured in ticks. */
    uint16 positionReg;  /*!< The value to be written to the duty cycle register. */
    uint16 speed;        /*!< The speed limit of the servo, in ticks per servo period (or 0 for no limit). */
};

// Array of 
static volatile struct PWM_DATA XDATA pwmData[MAX_PWM_PINS];

// Bitmasks for keeping track of which pins are being used as servos.
// A 1 bit indicates that the pin is a servo pulse output pin.
// A 0 but indicates that the pin will be used for something else and
// this library should not touch it.
static volatile uint8 pwmPinsOnPort0;
static volatile uint8 pwmPinsOnPort1;


// Call back - for when the speed has been set
// static void setSpeed(__ACTUATOR *actuator, DRIVE_SPEED speed){
/// speed ranges from -127 to 127.
void setMotorSpeed(MOTOR *motor, int8 speed){
	// MOTOR* motor = (MOTOR*)actuator;
	// const TimerCompare* channel = compareFromIOPin(motor->pwm);
	// const Timer* timer = compareGetTimer(channel);
	// uint16 top = timerGetTOP(timer);
	uint32 top = 0x70000; //458752 clock cycles = 19.11ms*(1/24 us/clock cycle)

	// New compare threshold
	uint32 delay = 0;

	if( speed > 0 ){
		delay = interpolateU(speed, 0, DRIVE_SPEED_MAX, 0 , top);

		// Set direction1 high, direction2 low
		// pin_make_output(motor->direction1,TRUE);
		// pin_make_output(motor->direction2,FALSE);
		// P1DIR |= (motor->direction1); //Enable pin P1_1
		// P1DIR &= ~(motor->direction2); //Disable pin P1_3
		setDigitalOutput(11, HIGH);
		setDigitalOutput(13, LOW);
	}else if(speed < 0){
		delay = interpolateU(speed, 0, DRIVE_SPEED_MIN,  0 , top);

		// Set direction1 low, direction2 high low
		// pin_make_output(motor->direction1,FALSE);
		// pin_make_output(motor->direction2,TRUE);
		// P1DIR &= ~motor->direction1; //Disable pin P1_1
		// P1DIR |= motor->direction2; //Enable pin P1_3
		setDigitalOutput(11, LOW);
		setDigitalOutput(13, HIGH);
	}else{
		// brake

		if(motor->direction2){
			// There are two direction pins - so set both to same value
			// pin_make_output(motor->direction1,FALSE);
			// pin_make_output(motor->direction2,FALSE);
			// P1DIR &= ~motor->direction1; //Disable pin P1_1
			// P1DIR &= ~motor->direction2; //Disable pin P1_3
			setDigitalOutput(11, LOW);
			setDigitalOutput(13, LOW);
		}else{
			// Only has one direction pin
			// Set direction1 to an input with no pullup ie disconnect
			// pin_make_input(motor->direction1,FALSE);
			P1DIR &= ~motor->direction1; //Disable pin P1_1
			setDigitalOutput(11, LOW);
		}
	}

	// Change the duty cycle
	// compareSetThreshold(channel,delay);
	// servoSetTarget();
	pwmSetTargetHighRes(motor->pwmpin, delay);
	motor->pwmval = delay;
}

void pwmSetTarget(uint8 pinNum, uint32 targetMicroseconds)
{
    // Convert the units of target from microseconds to timer ticks.
    pwmSetTargetHighRes(pinNum, targetMicroseconds * SERVO_TICKS_PER_MICROSECOND);
}

void pwmSetTargetHighRes(uint8 pinNum, uint32 target)
{
	///?????
    volatile struct PWM_DATA XDATA * d = pwmData + pwmAssignment[pinNum];

    // TODO: return here if "target" is out of the valid range

    T1IE = 0; // Make sure we don't get interrupted in the middle of an update.

    // Make this function have an immediate effect, if necessary.
    if (d->speed == 0 || d->target == 0 || target == 0)
    {
        d->position = target;
        d->positionReg = ~target + 1;
    }
    else if (target != d->position)
    {
        motorsMovingFlag = 1;
    }

    d->target = target;

    T1IE = pwmStartedFlag; //Enable if PWM is enabled.
}

/// Copied from servo.c
static uint8 pinToInternalChannelNumber(uint8 pin)
{
    switch(pin)
    {
    case 2: return 0;
    case 3: return 1;
    case 4: return 2;
    case 12: return 3;
    case 11: return 4;
    case 10: return 5;
    default: return 0;
    }
}

void pwmStart(uint8 XDATA * pins, uint8 numPins)
{
    uint8 i;

    if (pwmStartedFlag)
    {
        pwmStop();
    }

    //// Configure the pins and initialize the internal data structures. ////

    // The user passes a null argument for pins, then don't reinitialize the pins.
    // This allows us to temporarily start and stop the servos without losing track
    // of the old speeds, targets, and positions.
    if (pins != 0)
    {
        pwmPinsOnPort0 = pwmPinsOnPort1 = 0;
        for (i = 0; i < MAX_PWM_PINS; i++)
        {
            pwmData[i].target = 0;
            pwmData[i].position = 0;
            pwmData[i].positionReg = 0;
            pwmData[i].speed = 0;

            if (i < numPins)
            {
                uint8 internalChannelNumber = pinToInternalChannelNumber(pins[i]);

                pwmAssignment[i] = internalChannelNumber;

                switch(internalChannelNumber)
                {
                case 0: P0_2 = 0; pwmPinsOnPort0 |= (1<<2); break;
                case 1: P0_3 = 0; pwmPinsOnPort0 |= (1<<3); break;
                case 2: P0_4 = 0; pwmPinsOnPort0 |= (1<<4); break;
                case 3: P1_2 = 0; pwmPinsOnPort1 |= (1<<2); break;
                case 4: P1_1 = 0; pwmPinsOnPort1 |= (1<<1); break;
                case 5: P1_0 = 0; pwmPinsOnPort1 |= (1<<0); break;
                }
            }
        }

        // Set all the pins being used to be general-purpose outputs driving low for now.
        P0SEL &= ~pwmPinsOnPort0; // ????
        P0DIR |= pwmPinsOnPort0; // ????
        P1SEL &= ~pwmPinsOnPort1;
        P1DIR |= pwmPinsOnPort1;

        if (pwmPinsOnPort0)
        {
            // Set PRIP0[1:0] to 11 (Timer 1 channel 2 - USART0).
            // I'm not sure why this is necessary, but if it is not set then
            // Timer 1 can not control P0_4, even if no other peripherals on Port 0 are enabled.
            P2DIR |= 0b11000000;
        }
    }

    //// Configure Timer 1 and interrupts ////

    // Turn off the timer and reset the counters.
    T1CTL = 0;
    T1CNTL = 0;  // resets high and low bytes
    pwmCounter = 0;

    // Configure Timer 1 Channels 0-2 to be in compare mode.  Set output on compare-up, clear on 0.
    // This means all three pulses will start at different times but end at the same time.
    // With this configuration, we can set T1CC0, T1CC1, or T1CC2 to -N to get a pulse of with N,
    // as long as N > 1.
    // We can set the register to -1 or 0 to disable the pulse.
    T1CCTL0 = T1CCTL1 = T1CCTL2 = 0b00011100;

    // Turn off all the pulses at first.
    T1CC0 = T1CC1 = T1CC2 = 0xFFFF;

    // Timer 1: Start free-running mode, counting from 0x0000 to 0xFFFF.
    T1CTL = 0b00000001;

    // Set the Timer 1 interrupt priority to 2, the second highest.
    IP0 &= ~(1<<1);
    IP1 |= (1<<1);
    T1IE = 1; // Enable the Timer 1 interrupt.
    EA = 1;   // Enable interrupts in general.

    pwmStartedFlag = 1;
}

void pwmStop(void)
{
    if (!pwmStartedFlag)
    {
        // The servos have already been stopped.
        return;
    }

    T1IE = 0;

    // Wait for the timer to overflow.
    while(!T1IF){};

    // Assuming that there were fewer than (2730 - MAX_SERVO_TARGET_MICROSECONDS) worth of
    // interrupts the time when T1IF was read as true and now, the timer has just
    // overflowed and the next servo pulses have not started yet.
    // Make the pins revert to GPIO outputs driving low:
    P0SEL &= ~pwmPinsOnPort0;
    P1SEL &= ~pwmPinsOnPort1;

    // Turn off Timer 1.
    T1CTL = 0;

    pwmStartedFlag = 0;
}



ISR(T1, 0)
{
    uint8 i;

    switch(pwmCounter++)
    {
    case 0:
        PERCFG &= ~(1<<6);  // PERCFG.T1CFG = 0:  Move Timer 1 to Alt. 1 location (P0_2, P0_3, P0_4)
        P0SEL |= pwmPinsOnPort0;
        T1CC0 = pwmData[0].positionReg;  // NOTE: T1CCx is buffered, so these commands
        T1CC1 = pwmData[1].positionReg;  // don't take effect until the next timer period.
        T1CC2 = pwmData[2].positionReg;
        break;

    case 3:
        PERCFG |= (1<<6);  // PERCFG.T1CFG = 1:  Move Timer 1 to Alt. 2 location (P1_2, P1_1, P1_0)
        P1SEL |= pwmPinsOnPort1;
        T1CC0 = pwmData[3].positionReg;
        T1CC1 = pwmData[4].positionReg;
        T1CC2 = pwmData[5].positionReg;
        break;

    case 1:
    case 4:
        // We are producing pulses during THIS period, so disable the pulses for the next timer period.
        T1CC0 = T1CC1 = T1CC2 = 0xFFFF;
        break;

    case 2:
        // The pulses on port 0 just finished, so assign the pins to be GPIO (driving low) again.
        P0SEL &= ~pwmPinsOnPort0;
        break;

    case 5:
        // The pulses on port 1 just finished, so assign the pins to be GPIO (driving low) again.
        P1SEL &= ~pwmPinsOnPort1;
        break;

    case 6:
        // Set the counter back to zero so that next time we will start over at the beginning.
        pwmCounter = 0;

        // Update the positions of all the servos according to their speed limits,
        // and update motorsMovingFlag.

        // David measured how long these updates take, and it is only about 70us even if there is
        // a speed limit enabled for all channels.
        // WARNING: The SDCC manual warns that 16-bit division, multiplication, and modulus are implemented
        // using external support routines that are not reentrant, so we can't do any of those operations here!
        // The assembly generated by this ISR in servo.lst should be checked whenever making changes to the ISR.

        motorsMovingFlag = 0;

        for(i = 0; i < MAX_PWM_PINS; i++)
        {
            volatile struct PWM_DATA XDATA * d = pwmData + i;
            uint16 pos = d->position;

            if (d->speed && pos)
            {
                if (d->target > pos)
                {
                    if (d->target - pos < d->speed)
                    {
                        pos = d->target;
                    }
                    else
                    {
                        pos += d->speed;
                        motorsMovingFlag = 1;
                    }
                }
                else
                {
                    if (pos - d->target < d->speed)
                    {
                        pos = d->target;
                    }
                    else
                    {
                        pos -= d->speed;
                        motorsMovingFlag = 1;
                    }
                }
            }
            else
            {
                pos = d->target;
            }
            d->position = pos;
            d->positionReg = ~pos + 1;
        }

        break;
    }
} // end of ISR(T