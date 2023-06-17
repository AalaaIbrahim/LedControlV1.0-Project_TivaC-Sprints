/**
 ** @file      main.c
 ** @brief     
 ** @author    
 ** @date      June 16, 2023
 ** @version   0.1
 */

/*- INCLUDES
----------------------------------------------*/
#include "app.h"
#include "systick_interface.h"

int main(void)
{

    st_systick_cfg_t st_systick_cfg = {
            .en_systick_clk_src = CLK_SRC_PIOSC,
            .bool_systick_int_enabled = FALSE
    };

    en_systick_error_t en_systick_error = systick_init(&st_systick_cfg);
    if(ST_OK == en_systick_error)
    {
        systick_ms_delay(1000);
    }else
    {
        unsigned char bte5a = 1;
    }


	while(1)
	{
		
	}
	
	return 0;
}
