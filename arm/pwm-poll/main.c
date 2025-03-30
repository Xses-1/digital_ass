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

        SETBIT(SYSAHBCLKCTRL, 9);  // provide clock to timer        

	SETBIT(TMR32B0TCR, 0);  // Enable timer 1
	UNSETBIT(TMR32B0TCR, 1);  // Unpause it

	SETBIT(TMR32B0MCR, 0);  // Enable interrupt MR0
	SETBIT(TMR32B0MCR, 1);  // Enable reset MR0
	UNSETBIT(TMR32B0MCR, 2);  // Disable stop MR0

	UNSETBIT(TMR32B0MCR, 3);  // Disable interrupt MR1
	UNSETBIT(TMR32B0MCR, 4);  // Disable reset MR1
	UNSETBIT(TMR32B0MCR, 5);  // Disable stop MR1

	UNSETBIT(TMR32B0MCR, 6);  // Disable interrupt MR2
	UNSETBIT(TMR32B0MCR, 7);  // Disable reset MR2
	UNSETBIT(TMR32B0MCR, 8);  // Disable stop MR2

	SETBIT(TMR32B0MCR, 9);  // Enable interrupt MR3
	UNSETBIT(TMR32B0MCR, 10);  // Disable reset MR3
	UNSETBIT(TMR32B0MCR, 11);  // Disable stop MR3
	
	SETWORD(TMR32B0PR, 7200); // Set prescale
	SETWORD(TMR32B0MR0, 8); // Set match register
	SETWORD(TMR32B0MR3, 9); // Set match register

	SETWORD(TMR32B0TC, 0);
	SETWORD(TMR32B0PC, 0);


	SETBIT(LPC_GPIO3_DIR, 0);
}

static void pin_low(void) {
	SETBIT(LPC_GPIO3_DATA, 0);
}

static void pin_high(void) {
	UNSETBIT(LPC_GPIO3_DATA, 0);
}

int main() {
	init();
	pin_high();
	UNSETBIT(TMR32B0IR, 3);
	UNSETBIT(TMR32B0IR, 0);
	while (1) {
		if (READBIT(TMR32B0IR, 3)) {
			// MR3 match
			pin_high();
			UNSETBIT(TMR32B0IR, 3);
		}
		else if (READBIT(TMR32B0IR, 0)) {
			// MR0 match
			pin_low();
			UNSETBIT(TMR32B0IR, 0);
		}
	}

	return 0; // If the radiation causes the loop to exit
}

void _start() {
}

