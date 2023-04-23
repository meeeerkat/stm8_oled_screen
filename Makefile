
SDCC=sdcc -lstm8 -mstm8 --out-fmt-ihx --std-sdcc11

.PHONY=clean, build

build: oled_screen.lib

test: test.ihx
	sudo stm8flash -c stlinkv2 -p stm8s003f3 -w test.ihx

test.ihx: oled_screen.lib
	${SDCC} test.c oled_screen.lib i2c/i2c.lib

oled_screen.lib: oled_screen.rel
	sdar -rc oled_screen.lib oled_screen.rel

oled_screen.rel: i2c/i2c.lib
	${SDCC} -c oled_screen.c i2c/i2c.lib

clean:
	rm *.lib *.mem *.rel *.ihx *.rst *.map *.lk *.sym *.asm *.lst 2> /dev/null
