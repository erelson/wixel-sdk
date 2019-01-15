/*
 * $Id: motorPWM.h,v 1.9 2010/10/08 00:15:46 clivewebster Exp $
 *
 * Revision History
 * ================
 * $Log: motorPWM.h,v $
 * Revision 1.9  2010/10/08 00:15:46  clivewebster
 * Add specific L293D DC motor 2 pin and 3 pin support
 *
 * Revision 1.8  2010/08/10 22:51:06  clivewebster
 * Allow both 2 pin (with tri state switch) or 3 pin for an h bridge like L293D
 *
 * Revision 1.7  2010/06/15 00:48:59  clivewebster
 * Add copyright license info
 *
 * Revision 1.6  2009/11/02 19:00:09  clivewebster
 * Added revision log
 *
 * ===========
 *
 * Copyright (C) 2010 Clive Webster (webbot@webbot.org.uk)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * motorPWM.h
 *
 *  Created on: 24-Mar-2009
 *      Author: Clive Webster
 *
 *  A motor driver that uses one PWM for speed, and one output pin for direction.
 *  This includes my motor drivers at:
 *  http://www.societyofrobots.com/member_tutorials/node/159
 */

#ifndef MOTORPWM_H_
#define MOTORPWM_H_

#include <wixel.h>
#include <uart0.h>
#include "print_number.h" // Local library for debug printing...

// #include "actuators.h"

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~From servo.h~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/
/*! This defines the units used by the high resolution functions in this library
 * to represent positions and targets. */
#define TICKS_PER_MICROSECOND    24


/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~From actuators.h~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/
#define DRIVE_SPEED_MIN   ((int8)-127)
#define DRIVE_SPEED_MAX ((int8) 127)

// #ifdef __cplusplus
// /* ===================== C Code ===============================================*/
// extern "C" {
// #endif


typedef struct s_motor{
    // The PWM IO pin the motor is connected to - must be a timer compare pin
    uint8 pwmpin;            // valid values are 3, 4, 10, 11
       
    uint8 direction1;    // The compulsory IO pin used to set the direction of the motor
    uint8 direction2;    // The optional IO pin that is normally NOT(direction1) unless breaking or coasting
} MOTOR;


// Define the standard constructor for a dc motor driver setup
#define MAKE_MOTOR_3_PIN(pwmpin, dir1pin, dir2pin) { pwmpin, dir1pin, dir2pin }
#define MAKE_MOTOR_2_PIN(pwmpin, dir1pin) { pwmpin, dir1pin, 0 }

///Simple case for now; Don't need motor driver abstraction
typedef MOTOR* XDATA MOTOR_LIST;

typedef struct s_motor_driver{
    const MOTOR_LIST* const motors;        // The motors
    uint8 num_motors;             // The total number of motors
} MOTOR_DRIVER;


#define MAKE_MOTOR_DRIVER(motorlst) { \
    motorlst, \
    (uint8)(sizeof(motorlst)/sizeof(MOTOR*)) \
}


// Use PWM output
// void motorPWMInit(MOTOR_DRIVER* driver, uint32_t freq);
void setMotorSpeed(MOTOR* motor, int8 speed);


/*! Sets the specified PWM pin's duty cycle in units of microseconds.
 * The duty cycle is the ratio targetMicroseconds / (1/frequency). 
 *
 * \param pinNum  A pin number; E.g. for pin P1_3, pinNum = 13
 *   Valid values are 3, 4, 10, 11.
 *
 * \param targetMicroseconds  The target position of the servo in units of
 *   microseconds.
 *   A value of 0 means to stop sending pulses, and takes effect immediately
 *
*/
void pwmSetTarget(uint8 pinNum, uint16 targetMicroseconds);

//! target is in clock cycles
void pwmSetTargetHighRes(uint8 pinNum, uint16 target);


/*! This function starts the library;
 * it sets up the PWM pins and the timer to be ready to send PWM
 * pulses.
 * This function should be called before any other functions in the MotorDriver 
 * library.
 *
 * \param pins  A pointer to an array of pin numbers that specifies which pins
 *   will be used to generate servo pulses.
 *   The pin numbers used in this array are the same as the pin numbers used
 *   in the GPIO library (see gpio.h).  There should be no repetitions in this
 *   array, and each entry must be one of:
 *   - 3 (for P0_3)
 *   - 4 (for P0_4)
 *     
 *      or
 *      
 *   - 10 (for P1_0)
 *   - 11 (for P1_1)
 *
 * \param numPins The size of the pin number array.
 *
 * The pins specified in the <b>pins</b> array will be configured as digital
 * outputs, and their targets will be initialized to 0 (no pulses).
 *
 * If the <b>pins</b> parameter is 0 (a null pointer), then this function skips
 * the initialization of the pins and the internal data structures of the
 * library.
 * This means that the servo pin assignments and targets
 * from before will be preserved.
 *
 * The parameters to this function define the correspondence of servo
 * numbers to pins.
 * The <b>servoNum</b> parameter in the other library functions can be thought
 * of as an index in the <b>pins</b> array.
 * For example, a <b>servoNumber</b> of 0 corresponds to <code>pins[0]</code>, the first pin
 * in the array.
 *
 * Example code:
 *
 * \code
uint8 CODE pins[] = {10, 11};  // Use P1_0 and P1_1 for pwm.
pwmStart((uint8 XDATA *)pins, sizeof(pins));
pwmSetTarget(10, 7);       // Affects pin P1_0
pwmSetTarget(11, 50);       // Affects pin P1_1
 * \endcode
 */
void pwmStart(uint8 XDATA * pins, uint8 numPins, uint16 frequency);

/*! Stops the library; stops sending servo pulses and turns off Timer 1.
 * After this function runs, the pins that were used for servo pulses will
 * all be configured as general-purpose digital outputs driving low.
 *
 * You can later restart the servo pulses by calling servosStart().
 *
 * This is a blocking function that can take up to 2.8 milliseconds to finish
 * because it ensures that the pulses are shut off cleanly without any
 * glitches. */
void pwmStop(void);

#endif /* MOTORPWM_H_ */
