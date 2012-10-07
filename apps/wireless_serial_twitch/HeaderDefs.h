///%s Expects a 'char *', 'unsigned char*' or 'uint8_t *'
///%d Expects an 'int', 'int8_t' or an 'int16_t'
///%ld Expects a 'long' or 'int32_t'
///%u Expects an 'uint8_t' or an 'uint16_t'
///%lu Expects an 'unsigned long' or 'uint32_t'
///%o Expects an 'uint8_t' or an 'uint16_t' and outputs the number in octal (base 8)
///%lo Expects an 'unsigned long' or 'uint32_t' and outputs the number in octal (base 8)
///%x Expects an 'uint8_t' or an 'uint16_t' and outputs the number in hexadecimal (base 16)
///%lx Expects an 'uint32_t' and outputs the number in hexadecimal (base 16)
///%% Expects no parameter and just outputs the '%' character
///%c Expects a 'char', 'signed char', 'int8_t', 'int16_t', 'int'
///%f Expects a 'float' or 'double'

#include <wixel.h>

// defines for turning various bits of output on/off
#define PRINT_IR_RANGE 0
#define PRINT_DEBUG_COMMANDER 1
#define PRINT_DEBUG_IK 0
#define PRINT_DEBUG_LOOP 0
#define PRINT_DEBUG 0
#define PRINT_DEBUG_AGITATOR 0

#define RIGHT_SERVO 62
#define LEFT_SERVO  63

#define RTN_LVL 1
#define MY_SERVO_SPEED 300

#define zTRUE 1
#define zFALSE 0

#define LISTEN UART2toXbee38400


// The scaling factor used in GaitDesigner when generating the gait
#define SCALE_X 1000

// extern void initServoLims();

// extern uint16_t s61pos;
// extern uint16_t s62pos;
// extern uint16_t s63pos;

// //Servo position limits, range from 0 to 1023

// extern uint16_t servo61Min;
// extern uint16_t servo61Max;
// extern uint16_t servo62Min;
// extern uint16_t servo62Max;
// extern uint16_t servo63Min;
// extern uint16_t servo63Max;


// short turnright;
// short turnleft;
// short gunbutton;
// short panicbutton;
// short infobutton;
// short agitbutton;

// extern uint16_t loopLengthList[];

// extern short walk;
// extern short turn;
// extern short light;
// extern short kneeling;
// extern short flopCnt;
// extern short panic;

////////////////
// The former contents of Commander.h
//#ifndef Commander_h
//#define Commander_h
//
//#define LISTEN UART2toXbee38400

/* bitmasks for buttons array */
#define BUT_R1      0x01
#define BUT_R2      0x02
#define BUT_R3      0x04
#define BUT_L4      0x08
#define BUT_L5      0x10
#define BUT_L6      0x20
#define BUT_RT      0x40
#define BUT_LT      0x80

uint8 CmdrReadMsgs(int8 *desiredGait, int8 *desiredDir, int8 *desiredSpeed);
void UseSouthPaw();

// variables used for reading messages
unsigned char vals[7];  // temporary values, moved after we confirm checksum_cmdr
int8 index_cmdr;              // -1 = waiting for new packet
uint8 checksum_cmdr;
// unsigned char southpaw; 

/// These could be more local in scope.
int8 buttonval;
int8 walkV;
int8 walkH;
int8 lookV;
int8 lookH;
// int walkSPD;
// float walkDIR;
