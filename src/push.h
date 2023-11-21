/*
 *  push.h
 */

enum
{
    IBUPROFEN, DIPHEMHYDRAMINE, PARACETAMOL, ASPIRIN, RESTOCK, CREDIT,
    NUM_PUSH //Amount of buttons
};


void push_init(void);
int push_done(unsigned which); 
