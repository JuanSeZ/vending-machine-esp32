/*
 *  Project 41-mqtt_00 - Austral - EAM
 *
 *  hw.h
 *      Hardware dependent code
 */


// DEPRECATED
enum
{
    NOHW,
    BUTTON1_PUSHED,
    BUTTON2_PUSHED,
    BUTTON3_PUSHED,
    BUTTON4_PUSHED,
    NUM_NEWS
};

#define BUTTON1_PRESSED 1
#define BUTTON2_PRESSED 2
#define BUTTON3_PRESSED 3
#define BUTTON4_PRESSED 4

void init_hw(void);         //  Called at power up
int get_board_num(void);    //  return board number
int verify_hw(void);        //  Verifies all input hardware
