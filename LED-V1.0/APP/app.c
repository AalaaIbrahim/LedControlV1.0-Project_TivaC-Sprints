/**
 * @file    :   app.c
 * @author  :   Hossam Elwahsh - https://github.com/HossamElwahsh
 * @brief   :   Program File contains all APP functions' implementation
 * @version :   0.1
 * @date    :   2023-06-17
 *
 * @copyright Copyright (c) 2023
 */

/*
 * Includes */
#include "app.h"

/*
 * Private Typedefs */
typedef enum{
    ALL_OFF = 0 ,
    RED_ON      ,
    GREEN_ON    ,
    BLUE_ON     ,
    ALL_ON      ,
    STATES_TOTAL
}app_state_t;

/*
 * Private MACROS/Defines */
#define RED_LED_PORT 		5 // Port F
#define RED_LED_PIN			1

#define GREEN_LED_PORT 	5 // Port F
#define GREEN_LED_PIN		3

#define BLUE_LED_PORT 	5 // Port F
#define BLUE_LED_PIN		2

#define BTN_PORT 				5 // Port F
#define BTN_PIN 				4


/*
 * Private Variables */
static app_state_t gl_u8_app_state = ALL_OFF;


void app_init(void)
{
    // init GPIO

    // init RGB LED

    // init BTN
}

void app_start(void)
{
    while(1)
    {
        // todo check button is pressed? go to next state

        switch (gl_u8_app_state) {

            case ALL_OFF:
            {
                // todo turn off all leds
                break;
            }
            case RED_ON:
            {
                // todo turn on red led only
                break;
            }
            case GREEN_ON:
            {
                // todo turn on green led only
                break;
            }
            case BLUE_ON:
            {
                // todo turn on blue led only
                break;
            }
            case ALL_ON:
            {
                // todo turn on all RGB
                break;
            }
            case STATES_TOTAL:
            default:
            {
                // bad state, reset to ALL_OFF
                gl_u8_app_state = ALL_OFF;
                break;
            }
        }
    }
}