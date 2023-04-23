#pragma once

enum RESOLUTION {RES_128x32, RES_128x64};

// DO NOT USE DIVISIONS !!!!!
#define OLED_SCREEN_128x32_BUFF_SIZE 128*4 // 128*32 bits
#define OLED_SCREEN_128x64_BUFF_SIZE 128*8 // 128*64 bits


void oled_screen__init(enum RESOLUTION res);

void oled_screen__on();
void oled_screen__off();

void oled_screen__write(uint8_t* buff);

uint16_t oled_screen__get_buff_size();
