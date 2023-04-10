#include <stdint.h>
#include <stdio.h>
#include "print.h"
#include "uart.h"
#include "STM8S103F3.h"


void main (void) {

  // switch to 16MHz (default is 2MHz)
  sfr_CLK.CKDIVR.byte = 0x00;
    
  // init UART for 19.2kBaud
  UART_begin(9600);
  
    
  // main loop
  uint8_t i=0;
  while(1) {
    // if byte received, send echo + 1
    printf("%u\n", i);
    i++;
  }

}
