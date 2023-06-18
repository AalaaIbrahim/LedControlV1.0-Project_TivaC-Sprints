/**
 * @file     btn_interface.h
 * @brief    header file to interface with a push button on TM4C123GH6PM
 * @author   Alaa Hisham
 * @date     June 17, 2023
 * @version  0.1
 */


#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_

/*----------------------------------------------------------/
/- ENUMS
/----------------------------------------------------------*/
/* button Pins */
typedef enum{
	BTN_PIN_0	=	0	,
	BTN_PIN_1			,
	BTN_PIN_2			,
	BTN_PIN_3			,
	BTN_PIN_4			,
	BTN_PIN_5			,
	BTN_PIN_6			,
	BTN_PIN_7			,
	BTN_PIN_TOTAL
}enu_btn_pin_t_;

/* button Ports */
typedef enum
{
	BTN_PORT_A	=	0	,
	BTN_PORT_B			,
	BTN_PORT_C			,
	BTN_PORT_D			,
	BTN_PORT_E			,
	BTN_PORT_F			,
	BTN_PORT_TOTAL
}enu_btn_port_t_;

typedef enum
{
	BTN_STATE_NOT_PRESSED = 0	,
	BTN_STATE_PRESSED			,
	BTN_STATE_TOTAL
}enu_btn_state_t_;

typedef enum
{
	BTN_INTERNAL_PULL_UP = 0	,
	BTN_INTERNAL_PULL_DOWN		,
	BTN_EXTERNAL_PULL_UP			,
	BTN_EXTERNAL_PULL_DOWN		,
	BTN_PULL_TOTAL
}enu_btn_pull_t_;

typedef enum
{
	BTN_ACTIVATED	= 0 ,
	BTN_DEACTIVATED  
}enu_btn_active_state_t_;

typedef enum
{
	BTN_STATUS_OK = 0			 ,
	BTN_STATUS_INVALID_PULL_TYPE ,
	BTN_STATUS_INVALID_STATE	 ,
	BTN_STATUS_DEACTIVATED
}enu_btn_status_code_t_;

/*----------------------------------------------------------/
/- STRUCTS
/----------------------------------------------------------*/
typedef struct
{
	enu_btn_port_t_				enu_btn_port 	  ;
	enu_btn_pin_t_ 				enu_btn_pin 	  ;	
	enu_btn_pull_t_				enu_btn_pull_type ;
	/** Read only */
	enu_btn_active_state_t_		enu_btn_activation;	
}str_btn_config_t_;

/*---------------------------------------------------------/
/- FUNCTION PROTOTYPES
/---------------------------------------------------------*/

/**
 * @brief Function to initialize a given button instance
 * 
 * @param ptr_str_btn_config            : pointer to the desired button structure
 * 
 * @return BTN_STATUS_OK 	            : When the operation is successful
 *         BTN_STATUS_INVALID_STATE		: Button structure pointer is a NULL_PTR
 *         BTN_STATUS_INVALID_PULL_TYPE : If the pull type field in button structure is set to invalid value
 */
enu_btn_status_code_t_ btn_init(str_btn_config_t_* ptr_str_btn_config);

enu_btn_status_code_t_ btn_deinit(str_btn_config_t_* ptr_str_btn_config);

/**
 * @brief Function to read the current button state 
 * 
 * @param ptr_str_btn_config            : pointer to the desired button structure
 * @param ptr_enu_btn_state             : pointer to variable to store the button state
 * 
 * @return BTN_STATUS_OK                : When the operation is successful
 *         BTN_STATUS_INVALID_STATE     : Button structure and/or button state pointers are NULL_PTRs
 *         BTN_STATUS_INVALID_PULL_TYPE : If the pull type field in button structure is set to invalid value
 *		   BTN_STATUS_DEACTIVATED		: If we are trying to read from a deactivated button
 */
enu_btn_status_code_t_ btn_read(str_btn_config_t_* ptr_str_btn_config, enu_btn_state_t_* ptr_enu_btn_state);


#endif /* BTN_INTERFACE_H_ */
