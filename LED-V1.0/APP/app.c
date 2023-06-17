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
#include "led_interface.h"

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
#define RED_LED_PORT 		LED_PORT_F // Port F
#define RED_LED_PIN			LED_PIN_1

#define GREEN_LED_PORT 	LED_PORT_F // Port F
#define GREEN_LED_PIN		LED_PIN_3

#define BLUE_LED_PORT 	LED_PORT_F // Port F
#define BLUE_LED_PIN		LED_PIN_2

#define BTN_PORT 				5 // Port F
#define BTN_PIN 				4


/*
 * Private Variables */
static app_state_t gl_u8_app_state = RED_ON;


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
                led_off(RED_LED_PORT, RED_LED_PIN);
                led_off(GREEN_LED_PORT, GREEN_LED_PIN);
                led_off(BLUE_LED_PORT, BLUE_LED_PIN);
                break;
            }
            case RED_ON:
            {
                led_on(RED_LED_PORT, RED_LED_PIN);
                break;
            }
            case GREEN_ON:
            {
                led_off(RED_LED_PORT, RED_LED_PIN);
                led_on(GREEN_LED_PORT, GREEN_LED_PIN);
                break;
            }
            case BLUE_ON:
            {
                led_off(GREEN_LED_PORT, GREEN_LED_PIN);
                led_on(BLUE_LED_PORT, BLUE_LED_PIN);
                break;
            }
            case ALL_ON:
            {
                led_on(RED_LED_PORT, RED_LED_PIN);
                led_on(GREEN_LED_PORT, GREEN_LED_PIN);
                led_on(BLUE_LED_PORT, BLUE_LED_PIN);
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