/*
 * buttons.c
 *
 *	Reads two push buttons as inputs
 *	to turn on and of two LEDs as outputs.
 *
 *  Created on: 27/07/2016
 *      Author: doc2
 */
#include <avr/io.h>
#include <util/delay.h>


/*
 * delay_ms(delay_in_ms)
 *
 * Delay the specified number of milliseconds.
 *
 * _delay_ms uses a floating point datatype if you call
 * that function in many places in your code then it becomes
 * very fat. An integer is enough for us.
 *
 */
void delay_ms(unsigned int xms)
{
	while (xms) {
		_delay_ms(0.96);
		xms--;
	}
}


/*
 * init_ports()
 *
 * Initialise the ports to be used
 */
void init_ports(void)
{
	/* Make bits 0 and 1 of PORTB inputs and bits 2 to 6 outputs*/
	DDRB = 0x3C & 0x03f;
	PORTB = 0;
}


/*
 * illuminate_leds(leds)
 *
 * Illuminate the six LEDs connected to bits 0 to 6
 * of Port B according to input leds.
 */
void illuminate_leds(int leds)
{
	PORTB = leds & 0xc;
}


void main(void)
{

	/* Initialise I/O Ports for use. */
	init_ports();

	/* Do forever... */
	/* Shifts two bits of the DDRB register to the left
	 *  to put the inputs from the buttons into
	 *  the output port location and illuminates the leds accordingly.
	 */
	while (1) {

		illuminate_leds(PINB << 2);
	}

	/* Cannot get here */
}



