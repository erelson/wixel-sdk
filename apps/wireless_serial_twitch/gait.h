// Auto generated by WebbotLib Gait Designer

#include "GaitRunner.h"
// The number of servo limbs
#define G8_NUM_LIMBS 3

// Define constants for each limb
#define G8_LIMB_SERVO_MIDDLE 0
#define G8_LIMB_SERVO_RIGHT 1
#define G8_LIMB_SERVO_LEFT 2

// Define constants for each animation sequence
#define G8_ANIM_WALK_STRAIGHT_SLOW 0
#define G8_ANIM_START 1
#define G8_ANIM_TURN_RIGHT 2
#define G8_ANIM_WALK_STRAIGHT_BACK_SLOW 3
#define G8_ANIM_WALK_STRAIGHT 4
#define G8_ANIM_TURN_SLOW 5
#define G8_ANIM_WALK_STRAIGHT_BACK 6


// The limb positions for animation number 0 Frame#0
static const  G8_LIMB_POSITION  limbs_0_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,33 , 123,42 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,33 , 123,42 , 0 )
};

// The limb positions for animation number 0 Frame#1
static const  G8_LIMB_POSITION  limbs_0_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 114,171 , 93,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 81,24 , 51 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 81,24 , 51 )
};

// The limb positions for animation number 0 Frame#2
static const  G8_LIMB_POSITION  limbs_0_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 207,171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 51,-51 , 84,0 , 76 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 51,-51 , 84,0 , 76 )
};

// The limb positions for animation number 0 Frame#3
static const  G8_LIMB_POSITION  limbs_0_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -57,24 , 84,-39 , 123,-36 , 51 ),
	MAKE_G8_LIMB_POSITION( -57,24 , 84,-39 , 123,-36 , 51 )
};

// The limb positions for animation number 0 Frame#4
static const  G8_LIMB_POSITION  limbs_0_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 )
};

// The limb positions for animation number 0 Frame#5
static const  G8_LIMB_POSITION  limbs_0_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 114,-171 , 93,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 )
};

// The limb positions for animation number 0 Frame#6
static const  G8_LIMB_POSITION  limbs_0_6[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 207,-171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 51,51 , 84,0 , -76 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 51,51 , 84,0 , -76 )
};

// The limb positions for animation number 0 Frame#7
static const  G8_LIMB_POSITION  limbs_0_7[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -54,0 , 81,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,39 , 123,36 , -51 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,39 , 123,36 , -51 )
};

// The limb positions for animation number 1 Frame#0
static const  G8_LIMB_POSITION  limbs_1_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -500,114 , 750,-171 , 750,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -500,0 , 750,0 , 750,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -500,0 , 750,0 , 750,0 , 0 )
};

// The limb positions for animation number 1 Frame#1
static const  G8_LIMB_POSITION  limbs_1_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( 0,-114 , 0,171 , 0,0 , -57 ),
	MAKE_G8_LIMB_POSITION( 0,0 , 0,0 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( 0,0 , 0,0 , 0,0 , 0 )
};

// The limb positions for animation number 2 Frame#0
static const  G8_LIMB_POSITION  limbs_2_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -75,0 , 111,0 , 114,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -69,-46 , 105,54 , 114,30 , 0 ),
	MAKE_G8_LIMB_POSITION( -69,46 , 105,-54 , 114,-30 , 0 )
};

// The limb positions for animation number 2 Frame#1
static const  G8_LIMB_POSITION  limbs_2_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -52,-228 , 78,342 , 174,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , 38 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , -38 )
};

// The limb positions for animation number 2 Frame#2
static const  G8_LIMB_POSITION  limbs_2_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -75,0 , 111,0 , 114,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -72,46 , 105,-84 , 117,0 , 38 ),
	MAKE_G8_LIMB_POSITION( -72,-46 , 105,84 , 117,0 , -38 )
};

// The limb positions for animation number 2 Frame#3
static const  G8_LIMB_POSITION  limbs_2_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -75,0 , 111,0 , 114,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -69,46 , 105,-54 , 114,-30 , 0 ),
	MAKE_G8_LIMB_POSITION( -69,-46 , 105,54 , 114,30 , 0 )
};

// The limb positions for animation number 2 Frame#4
static const  G8_LIMB_POSITION  limbs_2_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -52,228 , 78,-342 , 174,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , -38 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , 38 )
};

// The limb positions for animation number 2 Frame#5
static const  G8_LIMB_POSITION  limbs_2_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -72,0 , 108,0 , 114,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -69,-46 , 102,84 , 117,0 , -38 ),
	MAKE_G8_LIMB_POSITION( -69,46 , 102,-84 , 117,0 , 38 )
};

// The limb positions for animation number 3 Frame#0
static const  G8_LIMB_POSITION  limbs_3_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 )
};

// The limb positions for animation number 3 Frame#1
static const  G8_LIMB_POSITION  limbs_3_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 114,171 , 93,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 )
};

// The limb positions for animation number 3 Frame#2
static const  G8_LIMB_POSITION  limbs_3_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 207,171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 51,51 , 84,0 , -76 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 51,51 , 84,0 , -76 )
};

// The limb positions for animation number 3 Frame#3
static const  G8_LIMB_POSITION  limbs_3_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -57,-24 , 84,39 , 123,36 , -51 ),
	MAKE_G8_LIMB_POSITION( -57,-24 , 84,39 , 123,36 , -51 )
};

// The limb positions for animation number 3 Frame#4
static const  G8_LIMB_POSITION  limbs_3_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,33 , 123,42 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,33 , 123,42 , 0 )
};

// The limb positions for animation number 3 Frame#5
static const  G8_LIMB_POSITION  limbs_3_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 114,-171 , 93,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 81,24 , 51 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 81,24 , 51 )
};

// The limb positions for animation number 3 Frame#6
static const  G8_LIMB_POSITION  limbs_3_6[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 207,-171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 51,-51 , 84,0 , 76 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 51,-51 , 84,0 , 76 )
};

// The limb positions for animation number 3 Frame#7
static const  G8_LIMB_POSITION  limbs_3_7[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -54,0 , 81,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-39 , 123,-36 , 51 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-39 , 123,-36 , 51 )
};

// The limb positions for animation number 4 Frame#0
static const  G8_LIMB_POSITION  limbs_4_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,-19 , 81,27 , 123,30 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,33 , 123,42 , 0 )
};

// The limb positions for animation number 4 Frame#1
static const  G8_LIMB_POSITION  limbs_4_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 114,171 , 93,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -38,-20 , 57,21 , 81,18 , 38 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 81,24 , 51 )
};

// The limb positions for animation number 4 Frame#2
static const  G8_LIMB_POSITION  limbs_4_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 207,171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -38,20 , 57,-39 , 81,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 51,-51 , 84,0 , 76 )
};

// The limb positions for animation number 4 Frame#3
static const  G8_LIMB_POSITION  limbs_4_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -54,19 , 81,-30 , 123,-27 , 38 ),
	MAKE_G8_LIMB_POSITION( -57,24 , 84,-39 , 123,-36 , 51 )
};

// The limb positions for animation number 4 Frame#4
static const  G8_LIMB_POSITION  limbs_4_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -54,19 , 81,-27 , 123,-30 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 )
};

// The limb positions for animation number 4 Frame#5
static const  G8_LIMB_POSITION  limbs_4_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 114,-171 , 93,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -38,20 , 57,-21 , 81,-18 , -38 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 )
};

// The limb positions for animation number 4 Frame#6
static const  G8_LIMB_POSITION  limbs_4_6[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 207,-171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -38,-20 , 57,39 , 81,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 51,51 , 84,0 , -76 )
};

// The limb positions for animation number 4 Frame#7
static const  G8_LIMB_POSITION  limbs_4_7[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -54,0 , 81,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,-19 , 81,30 , 123,27 , -38 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,39 , 123,36 , -51 )
};

// The limb positions for animation number 5 Frame#0
static const  G8_LIMB_POSITION  limbs_5_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -75,0 , 111,0 , 114,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -72,-17 , 108,21 , 114,9 , 0 ),
	MAKE_G8_LIMB_POSITION( -72,17 , 108,-21 , 114,-9 , 0 )
};

// The limb positions for animation number 5 Frame#1
static const  G8_LIMB_POSITION  limbs_5_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -52,-228 , 78,342 , 174,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , 13 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , -13 )
};

// The limb positions for animation number 5 Frame#2
static const  G8_LIMB_POSITION  limbs_5_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -75,0 , 111,0 , 114,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -75,17 , 111,-30 , 114,0 , 13 ),
	MAKE_G8_LIMB_POSITION( -75,-17 , 111,30 , 114,0 , -13 )
};

// The limb positions for animation number 5 Frame#3
static const  G8_LIMB_POSITION  limbs_5_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -75,0 , 111,0 , 114,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -72,17 , 108,-21 , 114,-9 , 0 ),
	MAKE_G8_LIMB_POSITION( -72,-17 , 108,21 , 114,9 , 0 )
};

// The limb positions for animation number 5 Frame#4
static const  G8_LIMB_POSITION  limbs_5_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -52,228 , 78,-342 , 174,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , -13 ),
	MAKE_G8_LIMB_POSITION( -100,0 , 150,0 , 150,0 , 13 )
};

// The limb positions for animation number 5 Frame#5
static const  G8_LIMB_POSITION  limbs_5_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -72,0 , 108,0 , 114,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -72,-17 , 108,30 , 114,0 , -13 ),
	MAKE_G8_LIMB_POSITION( -72,17 , 108,-30 , 114,0 , 13 )
};

// The limb positions for animation number 6 Frame#0
static const  G8_LIMB_POSITION  limbs_6_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -57,19 , 87,-27 , 120,-30 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 )
};

// The limb positions for animation number 6 Frame#1
static const  G8_LIMB_POSITION  limbs_6_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 114,171 , 93,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -38,20 , 57,-21 , 81,-18 , -38 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 )
};

// The limb positions for animation number 6 Frame#2
static const  G8_LIMB_POSITION  limbs_6_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,-114 , 207,171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -38,-20 , 57,39 , 81,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 51,51 , 84,0 , -76 )
};

// The limb positions for animation number 6 Frame#3
static const  G8_LIMB_POSITION  limbs_6_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -54,-19 , 81,30 , 123,27 , -38 ),
	MAKE_G8_LIMB_POSITION( -57,-24 , 84,39 , 123,36 , -51 )
};

// The limb positions for animation number 6 Frame#4
static const  G8_LIMB_POSITION  limbs_6_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -57,0 , 84,0 , 123,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -54,-19 , 81,27 , 123,30 , 0 ),
	MAKE_G8_LIMB_POSITION( -54,-24 , 81,33 , 123,42 , 0 )
};

// The limb positions for animation number 6 Frame#5
static const  G8_LIMB_POSITION  limbs_6_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 114,-171 , 93,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -38,-20 , 57,21 , 81,18 , 38 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 81,24 , 51 )
};

// The limb positions for animation number 6 Frame#6
static const  G8_LIMB_POSITION  limbs_6_6[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -107,114 , 207,-171 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -38,18 , 57,-36 , 81,0 , 57 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 51,-51 , 84,0 , 76 )
};

// The limb positions for animation number 6 Frame#7
static const  G8_LIMB_POSITION  limbs_6_7[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -54,0 , 81,0 , 123,0 , -57 ),
	MAKE_G8_LIMB_POSITION( -54,21 , 81,-33 , 123,-27 , 39 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-39 , 123,-36 , 51 )
};

// The frames for animation number 0
static const  G8_FRAME  frames_0[8] = {
	MAKE_G8_FRAME(0, limbs_0_0),
	MAKE_G8_FRAME(150, limbs_0_1),
	MAKE_G8_FRAME(250, limbs_0_2),
	MAKE_G8_FRAME(350, limbs_0_3),
	MAKE_G8_FRAME(500, limbs_0_4),
	MAKE_G8_FRAME(650, limbs_0_5),
	MAKE_G8_FRAME(750, limbs_0_6),
	MAKE_G8_FRAME(850, limbs_0_7)
};

// The frames for animation number 1
static const  G8_FRAME  frames_1[2] = {
	MAKE_G8_FRAME(0, limbs_1_0),
	MAKE_G8_FRAME(1000, limbs_1_1)
};

// The frames for animation number 2
static const  G8_FRAME  frames_2[6] = {
	MAKE_G8_FRAME(0, limbs_2_0),
	MAKE_G8_FRAME(150, limbs_2_1),
	MAKE_G8_FRAME(350, limbs_2_2),
	MAKE_G8_FRAME(500, limbs_2_3),
	MAKE_G8_FRAME(650, limbs_2_4),
	MAKE_G8_FRAME(850, limbs_2_5)
};

// The frames for animation number 3
static const  G8_FRAME  frames_3[8] = {
	MAKE_G8_FRAME(0, limbs_3_0),
	MAKE_G8_FRAME(150, limbs_3_1),
	MAKE_G8_FRAME(250, limbs_3_2),
	MAKE_G8_FRAME(350, limbs_3_3),
	MAKE_G8_FRAME(500, limbs_3_4),
	MAKE_G8_FRAME(650, limbs_3_5),
	MAKE_G8_FRAME(750, limbs_3_6),
	MAKE_G8_FRAME(850, limbs_3_7)
};

// The frames for animation number 4
static const  G8_FRAME  frames_4[8] = {
	MAKE_G8_FRAME(0, limbs_4_0),
	MAKE_G8_FRAME(150, limbs_4_1),
	MAKE_G8_FRAME(250, limbs_4_2),
	MAKE_G8_FRAME(350, limbs_4_3),
	MAKE_G8_FRAME(500, limbs_4_4),
	MAKE_G8_FRAME(650, limbs_4_5),
	MAKE_G8_FRAME(750, limbs_4_6),
	MAKE_G8_FRAME(850, limbs_4_7)
};

// The frames for animation number 5
static const  G8_FRAME  frames_5[6] = {
	MAKE_G8_FRAME(0, limbs_5_0),
	MAKE_G8_FRAME(150, limbs_5_1),
	MAKE_G8_FRAME(350, limbs_5_2),
	MAKE_G8_FRAME(500, limbs_5_3),
	MAKE_G8_FRAME(650, limbs_5_4),
	MAKE_G8_FRAME(850, limbs_5_5)
};

// The frames for animation number 6
static const  G8_FRAME  frames_6[8] = {
	MAKE_G8_FRAME(0, limbs_6_0),
	MAKE_G8_FRAME(150, limbs_6_1),
	MAKE_G8_FRAME(250, limbs_6_2),
	MAKE_G8_FRAME(350, limbs_6_3),
	MAKE_G8_FRAME(500, limbs_6_4),
	MAKE_G8_FRAME(650, limbs_6_5),
	MAKE_G8_FRAME(750, limbs_6_6),
	MAKE_G8_FRAME(850, limbs_6_7)
};
const  G8_ANIMATION  animations[7] = {
	MAKE_G8_ANIMATION(8, frames_0, FALSE),
	MAKE_G8_ANIMATION(2, frames_1, 2),
	MAKE_G8_ANIMATION(6, frames_2, FALSE),
	MAKE_G8_ANIMATION(8, frames_3, FALSE),
	MAKE_G8_ANIMATION(8, frames_4, FALSE),
	MAKE_G8_ANIMATION(6, frames_5, FALSE),
	MAKE_G8_ANIMATION(8, frames_6, FALSE)
};
