// Auto generated by WebbotLib Gait Designer

#include "GaitRunner.h"
// The number of servo limbs
#define G8_NUM_LIMBS 3

// Define constants for each limb
#define G8_LIMB_SERVO_MIDDLE 0
#define G8_LIMB_SERVO_RIGHT 1
#define G8_LIMB_SERVO_LEFT 2

// Define constants for each animation sequence
#define G8_ANIM_DEFAULT 0
#define G8_ANIM_START 1
#define G8_ANIM_WALK_STRAIGHT 2


// The limb positions for animation number 0 Frame#0
static const  G8_LIMB_POSITION  limbs_0_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -36,0 , 54,0 , 51,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -36,0 , 54,0 , 51,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -36,0 , 54,0 , 51,0 , 0 )
};

// The limb positions for animation number 0 Frame#1
static const  G8_LIMB_POSITION  limbs_0_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -228,-50 , 342,75 , 348,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -234,0 , 351,0 , 345,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -234,0 , 351,0 , 345,0 , 0 )
};

// The limb positions for animation number 0 Frame#2
static const  G8_LIMB_POSITION  limbs_0_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -230,50 , 345,-75 , 354,0 , 25 ),
	MAKE_G8_LIMB_POSITION( -236,0 , 354,0 , 351,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -236,0 , 354,0 , 351,0 , 0 )
};

// The limb positions for animation number 1 Frame#0
static const  G8_LIMB_POSITION  limbs_1_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -498,142 , 747,-213 , 750,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -498,0 , 747,0 , 750,0 , 0 ),
	MAKE_G8_LIMB_POSITION( -498,0 , 747,0 , 750,0 , 0 )
};

// The limb positions for animation number 1 Frame#1
static const  G8_LIMB_POSITION  limbs_1_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( 3,-142 , -3,213 , 0,0 , -71 ),
	MAKE_G8_LIMB_POSITION( 0,0 , 0,0 , 0,0 , 0 ),
	MAKE_G8_LIMB_POSITION( 0,0 , 0,0 , 0,0 , 0 )
};

// The limb positions for animation number 2 Frame#0
static const  G8_LIMB_POSITION  limbs_2_0[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -60,0 , 90,0 , 123,0 , -51 ),
	MAKE_G8_LIMB_POSITION( -57,-21 , 87,30 , 123,42 , 0 ),
	MAKE_G8_LIMB_POSITION( -57,-21 , 87,30 , 123,42 , 0 )
};

// The limb positions for animation number 2 Frame#1
static const  G8_LIMB_POSITION  limbs_2_1[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -23,-63 , 30,114 , 87,0 , -51 ),
	MAKE_G8_LIMB_POSITION( -35,-28 , 54,30 , 75,24 , 51 ),
	MAKE_G8_LIMB_POSITION( -35,-26 , 54,27 , 75,24 , 51 )
};

// The limb positions for animation number 2 Frame#2
static const  G8_LIMB_POSITION  limbs_2_2[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -31,-60 , 51,69 , 84,42 , 0 ),
	MAKE_G8_LIMB_POSITION( -37,30 , 54,-57 , 87,0 , 77 ),
	MAKE_G8_LIMB_POSITION( -37,26 , 54,-51 , 87,0 , 76 )
};

// The limb positions for animation number 2 Frame#3
static const  G8_LIMB_POSITION  limbs_2_3[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -58,0 , 87,0 , 120,0 , 51 ),
	MAKE_G8_LIMB_POSITION( -55,25 , 81,-39 , 123,-36 , 50 ),
	MAKE_G8_LIMB_POSITION( -55,24 , 81,-39 , 123,-36 , 51 )
};

// The limb positions for animation number 2 Frame#4
static const  G8_LIMB_POSITION  limbs_2_4[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -54,0 , 81,0 , 123,0 , 51 ),
	MAKE_G8_LIMB_POSITION( -54,24 , 81,-33 , 123,-42 , 0 ),
	MAKE_G8_LIMB_POSITION( -57,24 , 87,-33 , 120,-42 , 0 )
};

// The limb positions for animation number 2 Frame#5
static const  G8_LIMB_POSITION  limbs_2_5[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -29,60 , 39,-111 , 90,0 , 51 ),
	MAKE_G8_LIMB_POSITION( -35,26 , 54,-27 , 81,-24 , -51 ),
	MAKE_G8_LIMB_POSITION( -35,28 , 54,-30 , 81,-24 , -51 )
};

// The limb positions for animation number 2 Frame#6
static const  G8_LIMB_POSITION  limbs_2_6[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -25,63 , 42,-75 , 78,-39 , 0 ),
	MAKE_G8_LIMB_POSITION( -37,-26 , 54,51 , 78,0 , -76 ),
	MAKE_G8_LIMB_POSITION( -37,-28 , 54,54 , 78,0 , -77 )
};

// The limb positions for animation number 2 Frame#7
static const  G8_LIMB_POSITION  limbs_2_7[G8_NUM_LIMBS] = {
	MAKE_G8_LIMB_POSITION( -58,0 , 87,0 , 126,0 , -51 ),
	MAKE_G8_LIMB_POSITION( -58,-21 , 87,33 , 126,39 , -51 ),
	MAKE_G8_LIMB_POSITION( -58,-21 , 87,33 , 126,39 , -51 )
};

// The frames for animation number 0
static const  G8_FRAME  frames_0[3] = {
	MAKE_G8_FRAME(0, limbs_0_0),
	MAKE_G8_FRAME(69, limbs_0_1),
	MAKE_G8_FRAME(531, limbs_0_2)
};

// The frames for animation number 1
static const  G8_FRAME  frames_1[2] = {
	MAKE_G8_FRAME(1, limbs_1_0),
	MAKE_G8_FRAME(1000, limbs_1_1)
};

// The frames for animation number 2
static const  G8_FRAME  frames_2[8] = {
	MAKE_G8_FRAME(0, limbs_2_0),
	MAKE_G8_FRAME(153, limbs_2_1),
	MAKE_G8_FRAME(247, limbs_2_2),
	MAKE_G8_FRAME(351, limbs_2_3),
	MAKE_G8_FRAME(500, limbs_2_4),
	MAKE_G8_FRAME(650, limbs_2_5),
	MAKE_G8_FRAME(750, limbs_2_6),
	MAKE_G8_FRAME(845, limbs_2_7)
};
const  G8_ANIMATION  animations[3] = {
	MAKE_G8_ANIMATION(3, frames_0, FALSE),
	MAKE_G8_ANIMATION(2, frames_1, TRUE),
	MAKE_G8_ANIMATION(8, frames_2, FALSE)
};
