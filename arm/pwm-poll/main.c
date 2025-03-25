#include "delay.h"
#include "delay.c"
#include "LPC13xx.h"
#include "fuckit.h"

#define SETWORD(addr, word) \
	*(volatile uint32_t *) addr = word;
#define SETBIT(addr, bit) \
	*(volatile uint32_t *) addr |= 1 << bit;
#define UNSETBIT(addr, bit) \
	*(volatile uint32_t *) addr &= ~(1 << bit);
#define FLIPBIT(addr, bit) \
	*(volatile uint32_t *) addr ^= (1 << bit);
#define READBIT(addr, bit) \
	(((*(volatile uint32_t *) addr) & (1 << bit)) != 0)

static void init (void) {
	SETBIT(TMR32B0TCR, 0);  // Enable timer 1
	UNSETBIT(TMR32B0TCR, 1);  // Unpause it

	UNSETBIT(TMR32B0MCR, 0);  // Disable interrupt MR0
	SETBIT(TMR32B0MCR, 1);  // Enable reset MR0
	UNSETBIT(TMR32B0MCR, 2);  // Disable stop MR0

	UNSETBIT(TMR32B0MCR, 3);  // Disable interrupt MR1
	UNSETBIT(TMR32B0MCR, 4);  // Disable reset MR1
	UNSETBIT(TMR32B0MCR, 5);  // Disable stop MR1

	UNSETBIT(TMR32B0MCR, 6);  // Disable interrupt MR2
	UNSETBIT(TMR32B0MCR, 7);  // Disable reset MR2
	UNSETBIT(TMR32B0MCR, 8);  // Disable stop MR2

	UNSETBIT(TMR32B0MCR, 9);  // Disable interrupt MR3
	UNSETBIT(TMR32B0MCR, 10);  // Disable reset MR3
	UNSETBIT(TMR32B0MCR, 11);  // Disable stop MR3
	
	SETWORD(TMR32B0PR, 1200); // Set prescale
	SETWORD(TMR32B0MR0, 80); // Set match register
	SETWORD(TMR32B0MR3, 100); // Set match register
}

static void pin_low(void) {
	SETBIT(GPIO3DATA, 0);
}

static void pin_high(void) {
	UNSETBIT(GPIO3DATA, 0);
}

int main() {
	int prev_state, current_state;
	prev_state = READBIT(GPIO2DATA, 9);

	init();
	pin_low();
	while (1) {
	}
}

void _start() {
}

