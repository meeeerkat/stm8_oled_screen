#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "oled_screen.h"
#include "STM8S103F3.h"


uint8_t buff[OLED_SCREEN_128x32_BUFF_SIZE];


void main (void) {

  oled_screen__init(RES_128x32);

  oled_screen__on();


  memset(buff, 0, sizeof(buff));
  
  memset(buff, 0xFF, 100);
  memset(buff+200, 0xFF, 100);

  oled_screen__write(buff);
}
