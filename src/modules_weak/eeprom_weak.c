
#include "whale_eeprom.h"

#define _WEAK_ __attribute__((weak))
#define UNIMPLEMENTED (-1)

_WEAK_ w_eeprom_init(void) { return UNIMPLEMENTED };
_WEAK_ w_eeprom_full_erase(void);
_WEAK_ w_eeprom_write(int page, uint8_t addr, uint8_t src, int size);
_WEAK_ w_eeprom_read(int page, uint8_t addr, uint8_t *dst, int size);

