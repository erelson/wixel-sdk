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

#define RTN_LVL 1
#define MY_SERVO_SPEED 300

#define zTRUE 1
#define zFALSE 0

#define LISTEN UART2toXbee38400
// #define LISTEN UART0toUSB38400

// short derp;

// extern int do_gait;// = 1;

// extern void initTrig();  //function prototype
					// //function was in servoPosConsts.h

// extern void initServoLims();  //function prototype

// extern void setAXposition(int16_t, DYNAMIXEL_AX12, int16_t, int16_t);
// extern void myServoSpeeds(DYNAMIXEL_AX12_LIST*);
// extern void myServoReturnLevels(DYNAMIXEL_AX12_LIST*);
// extern void g8Stand();
// extern void g8FeetDown();
// extern void g8Flop();
// extern void walkNewDirIK(int16_t);
// extern void initTrig();
// extern void initServoLims();
// extern void agitatorLogic(TICK_COUNT);

// extern void turnCode(short,int16_t,int16_t);
// extern void walkCode(int16_t,int16_t,int16_t,int16_t);

// extern TICK_COUNT speedPhaseFix(TICK_COUNT, TICK_COUNT, TICK_COUNT);

/*extern void doLegKinematics(uint16_t, uint16_t*, uint16_t*, uint16_t*, short, \
 			float, float, float, float, int16_t, float, short);
*/
// extern uint8_t calc_foot_h(int16_t, uint16_t, float, int16_t, float, float);

//Servo position variables; defaulting these to centered...
// uint32 s11pos;
// uint32 s12pos;
// uint32 s13pos;
// extern uint16 s14pos;

// extern uint16_t s21pos;
// extern uint16_t s22pos;
// extern uint16_t s23pos;
// extern uint16_t s24pos;

// extern uint16_t s31pos;
// extern uint16_t s32pos;
// extern uint16_t s33pos;
// extern uint16_t s34pos;

// extern uint16_t s41pos;
// extern uint16_t s42pos;
// extern uint16_t s43pos;
// extern uint16_t s44pos;

// extern uint16_t s51pos; // added a 45� offset
// extern uint16_t s52pos;

// //Servo position limits, range from 0 to 1023
// extern uint16_t servo11Min; 
// extern uint16_t servo11Max;
// extern uint16_t servo12Min;
// extern uint16_t servo12Max;
// extern uint16_t servo13Min;
// extern uint16_t servo13Max;
// extern uint16_t servo14Min;
// extern uint16_t servo14Max;

// extern uint16_t servo21Min;
// extern uint16_t servo21Max;
// extern uint16_t servo22Min;
// extern uint16_t servo22Max;
// extern uint16_t servo23Min;
// extern uint16_t servo23Max;
// extern uint16_t servo24Min;
// extern uint16_t servo24Max;

// extern uint16_t servo31Min;
// extern uint16_t servo31Max;
// extern uint16_t servo32Min;
// extern uint16_t servo32Max;
// extern uint16_t servo33Min;
// extern uint16_t servo33Max;
// extern uint16_t servo34Min;
// extern uint16_t servo34Max;

// extern uint16_t servo41Min;
// extern uint16_t servo41Max;
// extern uint16_t servo42Min;
// extern uint16_t servo42Max;
// extern uint16_t servo43Min;
// extern uint16_t servo43Max;
// extern uint16_t servo44Min;
// extern uint16_t servo44Max;

// See WalkingOmni.nb
//Center angles for coax servo of each leg.plus test offsets.
// Measured from 0deg = front of bot
#define s11A0 225
#define s11Aoff 10
#define s21A0 -45 //315 //Hmmm no idea here....
#define s21Aoff -10
#define s31A0 45
#define s31Aoff 0
#define s41A0 135
#define s41Aoff 0


#define c_s11A0 cos(s11A0 + s11Aoff)
#define s_s11A0 sin(s11A0 + s11Aoff)
#define c_s21A0 cos(s21A0 + s21Aoff)
#define s_s21A0 sin(s21A0 + s21Aoff)
#define c_s31A0 cos(s31A0 + s31Aoff)
#define s_s31A0 sin(s31A0 + s31Aoff)
#define c_s41A0 cos(s41A0 + s41Aoff)
#define s_s41A0 sin(s41A0 + s41Aoff)


//Center angles for each leg.
// extern float servo11Ang;
// extern float servo21Ang;
// extern float servo31Ang;
// extern float servo41Ang;

// extern float cos_servo11Ang;
// extern float sin_servo11Ang;
// extern float cos_servo21Ang;
// extern float sin_servo21Ang;
// extern float cos_servo31Ang;
// extern float sin_servo31Ang;
// extern float cos_servo41Ang;
// extern float sin_servo41Ang;

// // Leg consts
// extern uint16_t bodyH;

// extern uint16_t L0;

	// //Leg part lengths
// #define preL12 58
// #define preL23 63
// #define preL34 67
// #define preL45 57

// extern uint16_t y11;
// extern uint16_t y21;
// extern uint16_t y31;
// extern uint16_t y41;

// extern int L12;
// extern int L23;
// extern int L34;
// extern int L45;

// extern int sqL23;
// extern int sqL34;
// //not used:
// //int sqL45 = preL45 * preL45;

// //????????
// extern int x11;
// extern int x21;
// extern int x31;
// extern int x41;

// //Leg ServoPos Offsets
// //  this is in units of... 10bit position?
// //  currently not used... manually entered values are in 
// extern int offsetServo1;
// extern int offsetServo2;
// extern int offsetServo3;
// extern int offsetServo4;

///////////////////////
/////TURRET////////////
///////////////////////
//+153 is 45 deg offset for pan servo's mounting scheme.
#define PAN_CENTER 511 + 153 
#define TILT_CENTER 511 + 95

uint8 d_tilt;
uint8 d_pan;
uint8 tilt_pos; // where tilt servo ought to be
uint8 pan_pos;  // where pan servo ought to be

// // 4*52 -> 60 degrees?
// extern uint16_t servo51Min;
// extern uint16_t servo51Max;
// extern uint16_t servo52Min;
// extern uint16_t servo52Max;

// extern int servo51Min;
// extern int servo51Max;
// extern int servo52Min;
// extern int servo52Max;



////////////////////
/////Timing/////////
///////////////////
// extern int16_t now2;
// extern int16_t now3;
// extern int16_t now4;
// extern int16_t now1;


// extern TICK_COUNT guns_firing_start_time;
// extern TICK_COUNT guns_firing_start_time;
// extern TICK_COUNT guns_firing_duration;
// extern TICK_COUNT spdChngOffset;

short turnright;
short turnleft;
short gunbutton;
short panicbutton;
short infobutton;
short agitbutton;

// extern uint16_t loopLengthList[];

// extern int16_t ang_dir;
short walk;
short turn;
short light;
short kneeling;
short flopCnt;
short panic;
// extern TICK_COUNT agitate;

uint8 pan_add;
uint8 tilt_add;


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

int CmdrReadMsgs();
void UseSouthPaw();

// variables used for reading messages
unsigned char vals[7];  // temporary values, moved after we confirm checksum_cmdr
int index_cmdr;              // -1 = waiting for new packet
int checksum_cmdr;
unsigned char southpaw; 

int walkV;
int walkH;
int lookV;
int lookH;
int walkSPD;
float walkDIR;
