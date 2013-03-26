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

// #include "actuators.h"

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~From servo.h~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/
/*! The maximum allowed target of a servo, in microseconds. */
#define SERVO_MAX_TARGET_MICROSECONDS  2500

/*! This defines the units used by the high resolution functions in this library
 * to represent positions and targets. */
#define SERVO_TICKS_PER_MICROSECOND    24


/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~From actuators.h~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/
#define DRIVE_SPEED_MIN   ((int8)-127)
#define DRIVE_SPEED_MAX ((int8) 127)

/// IOPin is an integer power of two, i.e. hexadecimal values from 2^0 to 2^7
// #define IOPin uint8

// #ifdef __cplusplus
// /* ===================== C Code ===============================================*/
// extern "C" {
// #endif

// typedef struct s_pwmpin{
	// //
	// uint8 pin; //Should be a pin value from the set [0,1,2,10,11,12] ??
	// uint32 val; // Pulse width in ticks (cycles; 1/24 us)
// } PWMPin;

typedef struct s_motor{
	// __ACTUATOR 	actuator;		// has all the common stuff
	// const IOPin *pwm;		
	// const IOPin *direction1;
	// const IOPin *direction2;
	uint32 pwmval;			// The PWM IO pin the motor is connected to - must be a timer compare pin
	uint8 pwmpin;			// uint8 CODE pins[] = {10, 12};  // Use P1_0 and P1_2 for servos.
	
	// directions are bitmask, i.e. integer powers of two, e.g. hexadecimal values from 2^0 to 2^7
	uint8 direction1;	// The compulsory IO pin used to set the direction of the motor
	uint8 direction2;	// The optional IO pin that is normally NOT(direction1) unless breaking or coasting
} MOTOR;


// #define MAKE_IOPIN(pin, val) {pin, val}
// Define the standard constructor for a dc motor - default to 2 pin
// #define MAKE_MOTOR_3_PIN(inverted, motorPin, directionPin1, directionPin2)  { MAKE_ACTUATOR(inverted),motorPin,directionPin1,directionPin2}
// #define MAKE_MOTOR_2_PIN(inverted, motorPin, directionPin)  MAKE_MOTOR_3_PIN(inverted,motorPin,directionPin,NULL)
// #define MAKE_MOTOR_3_PIN(pwmpin, dir1pin, dir2pin) { MAKE_IOPIN(pwmpin,0), dir1pin, dir2pin }
// #define MAKE_MOTOR_2_PIN(pwmpin, dir1pin) { MAKE_IOPIN(pwmpin,0), dir1pin, 0 }
#define MAKE_MOTOR_3_PIN(pwmpin, dir1pin, dir2pin) { pwmpin, dir1pin, dir2pin }
#define MAKE_MOTOR_2_PIN(pwmpin, dir1pin) { pwmpin, dir1pin, 0 }

// // For backwards compatibility
// #define MAKE_MOTOR(inverted, motorPin, directionPin)  MAKE_MOTOR_2_PIN(inverted, motorPin, directionPin)

///Simple case for now; Don't need motor driver abstraction
// typedef MOTOR* /*PROGMEM*/  MOTOR_LIST;

// typedef struct s_motor_driver{
	// const MOTOR_LIST* const motors;		// The motors
	// uint8_t num_motors; 			// The total number of motors
// } MOTOR_DRIVER;

/*
#define MAKE_MOTOR_DRIVER(motorlst) { \
	motorlst, \
	(uint8_t)(sizeof(motorlst)/sizeof(MOTOR*)) \
}
*/


// Use PWM output
// void motorPWMInit(MOTOR_DRIVER* driver, uint32_t freq);
void setMotorSpeed(MOTOR* motor, int8 speed);

// // Use code in Motors/L293D.c
// void motorL293Init(MOTOR_DRIVER* driver, uint32_t freq);

// // SN754410 is pseudonym for L293
// static __inline__ void motorSN754410Init(MOTOR_DRIVER* driver, uint32_t freq){
	// motorL293Init(driver, freq);
// }
// #ifdef __cplusplus
// }
// class Motor : public Actuator{
// public:
	// Motor(MOTOR* c) : Actuator(&c->actuator) {}
// };
// #endif

/*! Sets the specified servo's target position in units of microseconds.
 *
 * \param motorNum  A motor number between 0 and 5.
 *   This number should be less than the associated <b>numPins</b> parameter
 *   used in the last call to servosStart().
 *
 * \param targetMicroseconds  The target position of the servo in units of
 *   microseconds.
 *   A typical servo responds to pulse widths between 1000 and 2000 microseconds,
 *   so appropriate values for this parameter would be between 1000 and 2000.
 *   The full range of allowed values for this parameter is 0-2500.
 *   A value of 0 means to stop sending pulses, and takes effect
 *   immediately regardless of the speed limit for the servo.
 *
*/
void pwmSetTarget(uint8 pinNum, uint32 targetMicroseconds);

//! target is in clock cycles
void pwmSetTargetHighRes(uint8 pinNum, uint32 target);


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
 *   - 2 (for P0_2)
 *   - 3 (for P0_3)
 *   - 4 (for P0_4)
 *   - 10 (for P1_0)
 *   - 11 (for P1_1)
 *   - 12 (for P1_2)
 *
 * \param numPins The size of the pin number array.
 *
 * The pins specified in the <b>pins</b> array will be configured as digital
 * outputs, their targets will be initialized to 0 (no pulses), and their speed
 * limits will be initialized to 0 (no speed limit).
 *
 * If the <b>pins</b> parameter is 0 (a null pointer), then this function skips
 * the initialization of the pins and the internal data structures of the
 * library.
 * This means that the servo pin assignments, positions, targets, and speeds
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
uint8 CODE pins[] = {10, 12};  // Use P1_0 and P1_2 for servos.
PWMStart((uint8 XDATA *)pins, sizeof(pins));
servoSetTarget(0, 1500);       // Affects pin P1_0
servoSetTarget(1, 1500);       // Affects pin P1_2
 * \endcode
 */
void pwmStart(uint8 XDATA * pins, uint8 numPins);

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
