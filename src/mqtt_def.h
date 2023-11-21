#ifndef __MQTT_DEF_H__
#define __MQTT_DEF_H__

/*
 *  mqtt_def.h
 *
 *      This is not a traditional header file
 *      As a matter of fact, it has all the configurations for MQTT in one file
 *      Please, modify it with caution
 */

/*
 *  type definifitions
 */

typedef struct
{
    const char *sub_topic;
    void (*action)( int origin, char *message );
} topic_t;

/*
 *  C1 -> List of topics and actions
 */

static const topic_t topics[] =
{
    // {   "clear", clear_leds },
    // {   "tr", toggle_red    },
    // {   "ty", toggle_yel    },
    // {   "tg", toggle_grn    },
    // {   "ti", toggle_int    },
    // {   "sr", set_red       },
    // {   "sy", set_yel       },
    // {   "sg", set_grn       },
    // {   "si", set_int       },
    // {   "button", rx_button },
    // {   NULL }
};

/*
 *  C2 -> Subscriptions lists
 *
 *  Only for testing and studying purposes, you can select
 *  between 3 constants defined in platformio.ini
 */

static const char *subs[] =
{
#if (SUB_LIST==0)
    "#",
#elif (SUB_LIST==1)
    "+/ti",
    "82/si",
    "82/sr",
    "83/sy",
    "+/sg",
    "91/tr",
    "92/ty",
    "93/tg",
    "+/clear",
    "50/#",
    "+/button",
#elif (SUB_LIST==2)
    // "+/sr",
    // "00/sy",
    // "+/cy",
    // "+/clear",
#else
    #error "Bad SUB_LIST symbol, out of range"
#endif
    NULL
};

/*
 *  C3 -> Macros for id strings
 *      These are macros to define the following strings
 *
 *      id_string:      sub-string to log in broker (must be given the board number)
 *      topic_string:   sub-string to be used in topic publishing (must be given the board number)
 *      subs_string:    sub-string to be used in topic suubscription
 */

#define id_string(buf,brd)      sprintf(buf,"%s_%s_%02d",   MAIN_NAME,SUB_NAME,brd)
#define topic_string(buf,brd)   sprintf(buf,"%s/%s/%02d",   MAIN_NAME,SUB_NAME,brd)
#define subs_string(buf)        sprintf(buf,"%s/%s",        MAIN_NAME,SUB_NAME)

/*
 *  C4 -> broker selection
 */

#if (MQTT==0)                                       
    #define BROKER_NAME "172.22.42.93"         //  Mosquitto in local network
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#elif (MQTT==1)
    #define BROKER_NAME "44.218.56.34"          //  Mosquitto outside local network
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#elif (MQTT==2)
    //
    #define BROKER_NAME "35.174.87.19"    //  Remote broker by name, broker.mqtt-dashboard.com
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#else
    #error "Bad MQTT symbol, broker name out of range"
#endif

#endif      //  ends  __MQTT_DEF_H__

