///
// #include "ax.h"
// #include <wixel.h>

// // Send a command expecting no response
// void ax12Write8(const DYNAMIXEL_AX12* servo, uint8 cmd, uint8 data){
	// if(act_isConnected(servo)){
		// uint8 str[] = {servo->driver->writeCmd,cmd,data};
		// ax12Send(servo->driver, servo->id, sizeof(str), str);
	// }
// }

// // Send a command expecting no response
// void ax12Write16(const DYNAMIXEL_AX12* servo, uint8 cmd, uint16 data){
	// // if(act_isConnected(servo)){
	// uint8 str[] = {servo->driver->writeCmd,cmd,data & 0xff, (data>>8) & 0xff };
	// ax12Send(servo->driver, servo->id, sizeof(str), str);
	// // }
	// dynamixel_syncwrite(
// }