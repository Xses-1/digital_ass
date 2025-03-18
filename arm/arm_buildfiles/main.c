#include "delay.h"
#include "delay.c"
#include "LPC13xx.h"

#define GPIO3DIR LPC_GPIO3->DIR
#define GPIO3DATA LPC_GPIO3->DATA

#define SETBIT(addr, bit) \
	*(volatile uint32_t *) addr |= 1 << bit;
#define UNSETBIT(addr, bit) \
	*(volatile uint32_t *) addr &= ~(1 << bit);

static void wtfinit (void) {
	SETBIT(GPIO3DIR, 0);
}

static void led_off(void) {
	SETBIT(GPIO3DATA, 0);
}

static void led_on(void) {
	UNSETBIT(GPIO3DATA, 0);
}

int main() {
	wtfinit();
	init_delay();
	for (;;) {
		led_on();
		delay_ms(500);
		led_off();
		delay_ms(500);
	}
}

void _start() {
}

