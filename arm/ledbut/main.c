#include "delay.h"
#include "delay.c"
#include "LPC13xx.h"

//#define XSTR(x) STR(x)
//#define STR(x) #x
//#pragma message "The value of ABC: " XSTR(LPC_GPIO3)

//#define GPIO3DIR LPC_GPIO3->DIR
//#define GPIO3DATA LPC_GPIO3->DATA

#define GPIO3DIR 0x50038000
#define GPIO3DATA 0x50033FFC

#define GPIO2DIR 0x50028000
#define GPIO2DATA 0x50023FFC

#define SETBIT(addr, bit) \
	*(volatile uint32_t *) addr |= 1 << bit;
#define UNSETBIT(addr, bit) \
	*(volatile uint32_t *) addr &= ~(1 << bit);
#define FLIPBIT(addr, bit) \
	*(volatile uint32_t *) addr ^= (1 << bit);
#define READBIT(addr, bit) \
	(((*(volatile uint32_t *) addr) & (1 << bit)) != 0)

static void init (void) {
	SETBIT(GPIO3DIR, 0);
	UNSETBIT(GPIO2DIR, 9);
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
	int prev_state, current_state;
	prev_state = READBIT(GPIO2DATA, 9);

	init();
	//init_delay();
	while (1) {
		current_state = READBIT(GPIO2DATA, 9);
		if (current_state != prev_state && !current_state) {
			led_flip();
		}
		prev_state = current_state;
		delay_ms(25);
	}
}

void _start() {
}

