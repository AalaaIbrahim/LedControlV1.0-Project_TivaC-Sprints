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
#include "btn_interface.h"

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

#define USER_BTN_PORT 				BTN_PORT_F // Port F
#define USER_BTN_PIN 				BTN_PIN_4


/*
 * Private Variables */
static app_state_t gl_u8_app_state = RED_ON;

static str_btn_config_t_ gl_str_user_btn_cfg = {
        .enu_btn_port = USER_BTN_PORT,
        .enu_btn_pin  = USER_BTN_PIN,
        .enu_btn_activation = BTN_ACTIVATED,
        .enu_btn_pull_type = BTN_INTERNAL_PULL_UP
};

void app_init(void)
{
    // init RGB LED
    led_init(RED_LED_PORT, RED_LED_PIN);
    led_init(GREEN_LED_PORT, GREEN_LED_PIN);
    led_init(BLUE_LED_PORT, BLUE_LED_PIN);

    // init BTN
    btn_init(&gl_str_user_btn_cfg);
}

void app_start(void)
{
    while(1)
    {
        // todo check button is pressed? go to next state
        enu_btn_state_t_ enu_btn_state = BTN_STATE_NOT_PRESSED;
        btn_read(&gl_str_user_btn_cfg, &enu_btn_state);

        if(BTN_STATE_PRESSED == enu_btn_state)
        {
            if(ALL_ON == gl_u8_app_state)
            {
                gl_u8_app_state = ALL_OFF;
            }
            else
            {
                gl_u8_app_state += 1;
            }
        }
        else
        {
            /* Do Nothing */
        }

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