#include "../motorPWM.h"
#include "../timer.h"

// Call back - for when the speed has been set
static void setSpeed(__ACTUATOR *actuator, DRIVE_SPEED speed){
	MOTOR* motor = (MOTOR*)actuator;
	const TimerCompare* channel = compareFromIOPin(motor->pwm);
	const Timer* timer = compareGetTimer(channel);
	uint16_t top = timerGetTOP(timer);

	// New compare threshold
	uint16_t delay=0;

	if( speed > 0 ){
		delay = interpolateU(speed, 0, DRIVE_SPEED_MAX, 0 , top);

		// Set direction1 high, direction2 low
		pin_make_output(motor->direction1,TRUE);
		pin_make_output(motor->direction2,FALSE);
	}else if(speed < 0){
		delay = interpolateU(speed, 0, DRIVE_SPEED_MIN,  0 , top);

		// Set direction1 low, direction2 high low
		pin_make_output(motor->direction1,FALSE);
		pin_make_output(motor->direction2,TRUE);
	}else{
		// brake

		if(motor->direction2){
			// There are two direction pins - so set both to same value
			pin_make_output(motor->direction1,FALSE);
			pin_make_output(motor->direction2,FALSE);
		}else{
			// Only has one direction pin
			// Set direction1 to an input with no pullup ie disconnect
			pin_make_input(motor->direction1,FALSE);
		}
	}

	// Change the duty cycle
	compareSetThreshold(channel,delay);
}