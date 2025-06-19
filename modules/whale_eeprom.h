#ifndef WHALE_EEPROM_H
#define WHALE_EEPROM_H

#include <stdint.h>
#include <stdbool.h>
#include "hardware/i2c.h"
#include "hardware/gpio.h"

#define W_EEPROM_OK 0
#define W_EEPROM_ERR 1

#ifndef W_EEPROM_SEL
#define W_EEPROM_SEL (0x00)
#endif

#define W_SCL_PIN (5)
#define W_SDA_PIN (4)
#define W_I2C_INST (i2c0)

/*
 * using this library:
 * the read/write functions work with strings / uint8_t arrays of up to size 256
 * they will return an error if you try to write to a page or address out of bounds
 * or if you try to write more than 256 bytes at a time
 *
 * in your main program, #define W_EEPROM_SEL to be equal to the A2 and A1 bits
 * which are set physically with resistors. this allows a range of 0x00 to 0x03
 *
 * example:
 * 	w_eeprom_write(420, 0x45, ex_src_string, sizeof(ex_src_string));
 * 	w_eeprom_read(420, 0x45, ex_dst_string, sizeof(ex_dst_string));
 *
 * to read a single byte make sure to either use an array of size 1
 * or explicitly pass it a pointer!
 *
 * all functions return either W_EEPROM_OK or W_EEPROM_ERR
 */



int w_eeprom_init(void);

int w_eeprom_full_erase(void);

int w_eeprom_write(int page, uint8_t addr, uint8_t *src, int size);
int w_eeprom_read(int page, uint8_t addr, uint8_t *dst, int size);

int w_eeprom_is_busy_timeout(uint ms);

#endif
