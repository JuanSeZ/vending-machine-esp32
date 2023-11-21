/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *  hw.cpp
 *      Hardware dependent code
 */

#include <Arduino.h>

#include "hw.h"
#include "push.h"




int
get_board_num(void)
{
    return digitalRead(IB0) | (digitalRead(IB1) << 1); 
}

/*
 *  init_hw
 *      Called at power up
 */

void
init_hw(void)
{
    // Put in here any button you like
    push_init();
}
