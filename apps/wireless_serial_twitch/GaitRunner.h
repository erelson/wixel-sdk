/*
 * $Id: GaitRunner.h,v 1.2 2010/07/29 02:24:41 clivewebster Exp $
 * Revision History
 * ================
 * $Log: GaitRunner.h,v $
 * Revision 1.2  2010/07/29 02:24:41  clivewebster
 * *** empty log message ***
 *
 * Revision 1.1  2010/07/03 15:27:28  clivewebster
 * Added
 *
 * ================
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
 *
 *        File: GaitRunner.h
 *  Created on: 28 Jun 2010
 *      Author: Clive Webster
 *
 *  Responsible for running gaits in standalone mode
 */

#ifndef GAITRUNNER_H_
#define GAITRUNNER_H_

#include <wixel.h>
// #include "../libdefs.h"
// #include "../actuators.h"

#ifdef __cplusplus
/* ===================== C Code ===============================================*/
extern "C" {
#endif

/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~From libdefs.h~~~~~~~~~~~~**/
#define FALSE 0
#define TRUE  1
#define __inline__
#define  null ((void*)0)

	#define pgm_read_byte(addr) *addr
	#define pgm_read_word(addr) *addr

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~From actuators.h~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/
#define DRIVE_SPEED_MIN   ((int8)-127)
#define DRIVE_SPEED_MAX ((int8) 127)
// Define forward references
struct c_actuator_driver;

/*----------------------------------------------------------------------------------------
* An abstract datatype used by all of the different actuators.
* The only time when it is used by itself is a 'virtual' actuator where the device is
* connected to a 3rd party driver board - where we only talk to the controller board
* rather than to each actuator directly
-----------------------------------------------------------------------------------------*/

typedef struct s_actuator_common{
	const struct c_actuator_driver* sclass;// The driver class that controls this actuator
	int8	  required_speed;	// The last required speed that has been set. Note that the motor might not yet be at that speed. See encoders.
	boolean		  connected:1;		// When disconnected a device will freewheel, as opposed to speed=0 which will make it brake
	const boolean inverted:1;		// If TRUE then will reverse the direction of the motor ie it will use 'required_speed * -1'. So if your motor is
									// turning the wrong way then just flip this flag
} __ACTUATOR;

// Define the standard constructor for an actuator
// Start with a speed of -128 so that the next setSpeed is a change
#define MAKE_ACTUATOR_WITH_CLASS(class,inverted)  {class, -128 ,FALSE, inverted}
#define MAKE_ACTUATOR(inverted)  MAKE_ACTUATOR_WITH_CLASS(null,inverted)

typedef __ACTUATOR* /*PROGMEM*/  ACTUATOR_LIST;
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/


// Define the position of one limb
typedef struct s_limbPos{
	int16		cubeX,cubeY;
	int16		squareX,squareY;
	int16		timeX,timeY;
	int8	startY;
} G8_LIMB_POSITION;
#define MAKE_G8_LIMB_POSITION(cubeX,cubeY,squareX,squareY, timeX, timeY, startY) {cubeX,cubeY,squareX,squareY, timeX, timeY, startY}

// Define the position of all limbs for a given frame
typedef struct s_frame{
	uint16	time;				// This moment in time 0...1000
	const G8_LIMB_POSITION* limbs;	// The array of limb positions
} G8_FRAME;
#define MAKE_G8_FRAME(time, limbs) { time, limbs }

// Define one animation
typedef struct s_animation{
	const uint8				numFrames;		// Number of frames in this animation
	const G8_FRAME* const	frames;			// The array of frames
	const boolean			sweep;			// Does it sweep back and forth?
} G8_ANIMATION;
#define MAKE_G8_ANIMATION(numFrames, frames, sweep) { numFrames, frames, sweep }

// Define the gait runner itself
typedef struct s_runner{
	// const ACTUATOR_LIST* const 	actuators;		// The list of actuators to control
	const uint8*        	ids;
	const uint8 	 		num_actuators;	// The number of actuators in the list
	const G8_ANIMATION* const 	animations;	// The address of the animations array
	volatile uint8 			animation;		// The current animation
	volatile uint8			frame;			// The current frame in the animation
	volatile int16			repeatCount;	// Number of loops to play (0=forever)
	volatile boolean		playing;		// Is an animation current playing?
	volatile uint32			startTime;		// Time when the animation started
	volatile int16			currentTime;	// The current time offset
	volatile int16			totalTime;		// The total time required to play the animation
	volatile boolean		backwards;		// Are we playing the animation backwards
	volatile int8			speed;			// The speed of animation
	volatile int8*			speeds;			// The speed/position setting for each actuator
	volatile int8*			delta;			// The speed/position setting to add for each actuator
} G8_RUNNER;

#define MAKE_G8_RUNNER(list, animations) { list, \
		(uint8)(sizeof(list)/sizeof(__ACTUATOR*)), \
		animations, 0,0,0,false,0,0,0,false, 0, null,null };

// Initialise a gait runner from appInitHardware or appInitSoftware
void gaitRunnerInit(G8_RUNNER* runner);

// Start running a new animation
void gaitRunnerPlay(G8_RUNNER* runner, uint8 animation, int16 loopSpeed, int8 speed, int16 repeatCount);

// Stop the animation when it next reaches its last frame
static __inline__ void gaitRunnerStop(G8_RUNNER* runner){
	runner->repeatCount = (runner->speed < 0) ? -1 : 1;
}

// Update the gait runner and move servos to new positions
// Call it from your main loop or via the scheduler to do it in the background
// NB There is no point scheduling any faster than 20ms as that is the servo refresh rate
// Return true if an animation is playing
boolean gaitRunnerProcess(G8_RUNNER* runner);


static __inline__ boolean gaitRunnerIsPlaying(const G8_RUNNER* runner){
	return runner->playing;
}

static __inline__ int16 gaitRunnerRepeatCount(const G8_RUNNER* runner){
	return runner->repeatCount;
}

static __inline__ void gaitRunnerSetSpeed(G8_RUNNER* runner, int8 speed ){
	runner->speed = speed;
}
static __inline__ int8 gaitRunnerGetSpeed(const G8_RUNNER* runner ){
	return runner->speed;
}

void gaitRunnerSetDelta(G8_RUNNER* runner, uint8 limbNumber, int8 speed );
static __inline__ int8 gaitRunnerGetDelta(const G8_RUNNER* runner, uint8 limbNumber){
	return runner->delta[limbNumber];
}

#ifdef __cplusplus
}
#endif

#endif /* GAITRUNNER_H_ */
