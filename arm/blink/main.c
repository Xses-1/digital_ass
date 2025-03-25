#include "delay.h"
#include "delay.c"
#include "LPC13xx.h"

//#define XSTR(x) STR(x)
//#define STR(x) #x
//#pragma message "The value of ABC: " XSTR(LPC_GPIO3)

#define GPIO3DIR LPC_GPIO3_DIR
#define GPIO3DATA LPC_GPIO3_DATA

//#define GPIO3DIR 0x50038000
//#define GPIO3DATA 0x50033FFC

#define SETBIT(addr, bit) \
	*(volatile uint32_t *) addr |= 1 << bit;
#define UNSETBIT(addr, bit) \
	*(volatile uint32_t *) addr &= ~(1 << bit);
#define FLIPBIT(addr, bit) \
	*(volatile uint32_t *) addr ^= (1 << bit);

static void init (void) {
	SETBIT(GPIO3DIR, 0);
}

static void led_off(void) {
	SETBIT(GPIO3DATA, 0);
}

static void led_on(void) {
	UNSETBIT(GPIO3DATA, 0);
}

static void led_flip(void) {
	FLIPBIT(GPIO3DATA, 0);
}

int main() {
	init();
	//init_delay();
	while (1) {
		led_flip();
		delay_ms(50);
		led_flip();
		delay_ms(500);
	}
}

void _start() {
}

