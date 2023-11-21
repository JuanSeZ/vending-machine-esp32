/*
 *  push.h
 */

enum
{
    PENICILIN, TAFIROL, 
    NUM_PUSH //Amount of buttons
};


void push_init(void);
int push_done(unsigned which); 
