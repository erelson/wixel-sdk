
#include <wixel.h>
#include "Interpolate.h"

//////////////

/*
*    Interpolate between two signed numbers
*    value - the current value to be used
*   minVal - the minimum that 'value' can be
*   maxVal - the maximum that 'value' can be
*   minRtn - the return value if 'value = minVal'
*   maxRtn - the return value if 'value = maxVal'
*   return a value in the range minRtn to maxRtn
*/
int16 interpolate(int16 value, int16 minVal, int16 maxVal, int16 minRtn, int16 maxRtn){
    register int32  lRtnRange;
    register int32 lValRange;
    register int32 lRelVal;

    lRtnRange = maxRtn - minRtn;
    lValRange = maxVal - minVal;
    lRelVal = value - minVal;
    lRtnRange =  minRtn + ( lRtnRange * lRelVal / lValRange );
    return (int16)lRtnRange;
}

/*
*    Interpolate between two numbers
*    value - the current value to be used
*   minVal - the minimum that 'value' can be
*   maxVal - the maximum that 'value' can be
*   minRtn - the return value if 'value = minVal'
*   maxRtn - the return value if 'value = maxVal'
*   return a value in the range minRtn to maxRtn
*/
uint16 interpolateU(int16 value, int16 minVal, int16 maxVal, uint16 minRtn, uint16 maxRtn){
    register uint32  lRtnRange;
    register int32 lValRange;
    register int32 lRelVal;

    lRtnRange = maxRtn - minRtn;
    lValRange = maxVal - minVal;
    lRelVal = value - minVal;

    // Break into smaller operations - as doing in one statement gives wrong answers
    lRelVal *= lRtnRange;
    lRelVal /= lValRange;

    lRtnRange =  minRtn + lRelVal;

    return (uint16)lRtnRange;
}
