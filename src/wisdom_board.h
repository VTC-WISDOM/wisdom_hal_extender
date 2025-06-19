/* wisdom_board.h
 * some basic functions for the WiSDOM board itself
 */

#ifndef WISDOM_BOARD_H
#define WISDOM_BOARD_H

#include "hardware/adc.h"
#include "hardware/gpio.h"


void w_get_battery_volts(float *volts) {
	
	uint selected_adc = adc_get_selected_input();
	
	adc_gpio_init(26);
	adc_select_input(0);

	uint adc_reading = 0;
	for(int i = 0; i < 10; i++) {
		adc_reading += adc_read();
	}
	adc_reading = adc_reading / 10;

	const float conversion_factor = 6.6f / (1 << 12);
	*volts = adc_reading * conversion_factor;

	adc_select_input(selected_adc);
}
	


void w_get_temperature(float *temp) {

	uint selected_adc = adc_get_selected_input();

	adc_gpio_init(27);
	adc_select_input(1);

	adc_select_input(selected_adc);
}


#endif
