/**
 * \file Main.c
 *
 * \brief Initial firmware for V2X bring up
 *
 * Author: Jesse Banks (jbanks2)
 */

/**
 * \mainpage V2X Application documentation
 *
 *
 */

#include <asf.h>
#include "V2X/V2X.h"

#ifndef V2X_CLOCK_DEF
#warning Clock file is not updated. please follow instructions in src/V2X/clock_conf.h header.
#endif

int main ()
{
	v2x_board_init();	//configure pins and initial safe condition
	
	while (1){
		sleepmgr_enter_sleep();
		//led_update();
		if (usb_cdc_is_active(USB_ACL)) {report_accel_data();}
		charge_pump_toggle();		//charge pump pin needs toggled to create boost voltage for LEDs
	}
}