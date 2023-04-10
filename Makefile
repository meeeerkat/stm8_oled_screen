
SDCC=sdcc -lstm8 -mstm8 --out-fmt-ihx --std-sdcc11

.PHONY=clean, build

build: main.ihx

monitor: build
	sudo stm8flash -c stlinkv2 -p stm8s003f3 -w main.ihx
	sleep 1
	./uart/monitor.sh

main.ihx: uart/uart.lib
	${SDCC} -Iuart main.c uart/uart.lib

clean:
	rm *.lib *.mem *.rel *.ihx *.rst *.map *.lk *.sym *.asm *.lst 2> /dev/null
