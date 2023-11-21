/*
 *  push.cpp
 */

#include "push.h"

#include "button.h"

static const unsigned pin[NUM_PUSH] = { PENICILIN_BUTTON, TAFIROL_BUTTON };

Button btns[NUM_PUSH];

void
push_init(void)
{
    int i;
    unsigned const *p;

    for( i = 0, p = pin; i < NUM_PUSH; ++i )
        btns[i].begin(*p++);
}

int
push_done(unsigned which)
{
    if(which >= NUM_PUSH)       //  Verify that index is in array
        return 0;               //  Do nothing case in error

    return btns[which].debounce();
}
