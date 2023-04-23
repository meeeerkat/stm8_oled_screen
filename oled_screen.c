#include <stdint.h>
#include <stdio.h>
#include "i2c/i2c.h"
#include "oled_screen.h"
#include "STM8S103F3.h"

#define ADDR_128x32 0x3C
#define ADDR_128x64 0x3D



/*
 * Internal command arrays
 */
const uint8_t INIT_COMMANDS[] = {

  0x00,

  // Turn off
  0xAE,

  // Fundamental settings
  0x81,
  0x7F,

  0xA4,

  0xA6,

  // Deactivate scrolling
  0x2E,

  // Addressing settings
  0x00,

  0x10,

  0x20,
  0,

  0x21,
  0,
  127,

  0x22,
  0,
  3,

  0xB0,

  // Hardware settings
  0x40,

  0xA0,

  0xA8,
  31,

  0xC0,

  0xD3,
  0,

  0xDA,
  0b00001000,

  // Time settings
  0xD5,
  0x80,

  0xD9,
  0x22,

  0xDB,
  0x20,

  // Charge pump settings
  0x8D,
  0x14,

  // Deactivate scrolling
  0x2E,
};
const size_t INIT_COMMANDS_SIZE = sizeof(INIT_COMMANDS);


const uint8_t ON_COMMANDS[] = {
  0x00,
  0xAF
};
const size_t ON_COMMANDS_SIZE = sizeof(ON_COMMANDS);

const uint8_t OFF_COMMANDS[] = {
  0x00,
  0xAE
};
const size_t OFF_COMMANDS_SIZE = sizeof(OFF_COMMANDS);


/*
 * Internal structure
 */
uint8_t address;
uint16_t buff_size;


/*
 * Public methods
 */

void oled_screen__init(enum RESOLUTION res) {
  if (res == RES_128x32) {
    address = ADDR_128x32;
    buff_size = OLED_SCREEN_128x32_BUFF_SIZE;
  }
  else {
    address = ADDR_128x64;
    buff_size = OLED_SCREEN_128x64_BUFF_SIZE;
  }

  i2c__init();
  i2c__fullwrite(address, INIT_COMMANDS, INIT_COMMANDS_SIZE);
}

void oled_screen__on() {
  i2c__fullwrite(address, ON_COMMANDS, ON_COMMANDS_SIZE);
}
void oled_screen__off() {
  i2c__fullwrite(address, OFF_COMMANDS, OFF_COMMANDS_SIZE);
}

uint16_t oled_screen__get_buff_size() {
  return buff_size;
}

void oled_screen__write(uint8_t* buff) {
  i2c__start();
  i2c__write_addr(address, 0);
  i2c__write_byte(0b01000000);
  i2c__write_buff(buff, buff_size);
  i2c__stop();
}
