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


// extern void initServoLims();


/// NOTE: void return type for CmdrReadMsgs does not save any memory
uint8 ReadReceivedBytes(int8 *data1, int8 *data2);
void ProcessAction(int8 data1);

// variables used for reading messages
unsigned char vals[7];  // temporary values, moved after we confirm checksum_cmdr
int8 index_cmdr;              // -1 = waiting for new packet
uint8 checksum_cmdr;

/// These could be more local in scope.
// int8 buttonval; //moved to be local
int8 walkV;
int8 walkH;
int8 lookV;
int8 lookH;

uint16 onPos;
uint16 offPos;
