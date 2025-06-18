#ifndef WHALE_EEPROM_H
#define WHALE_EEPROM_H

#include <stdint.h>
#include <stdbool.h>
#include "hardware/i2c.h"
#include "hardware/gpio.h"

#define EEPROM_OK 0
#define EEPROM_ERR 1
#define EEPROM_BUSY 2

#ifndef EEPROM_A1
#define EEPROM_A1 (0)
#endif

#ifndef EEPROM_A2
#define EEPROM_A2 (0)
#endif

int w_eeprom_init(void);

int w_eeprom_full_erase(void);

int w_eeprom_write(int page, uint8_t addr, uint8_t *src, int size);
int w_eeprom_read(int page, uint8_t addr, uint8_t *dst, int size);

#endif
