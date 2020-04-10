/*	Author: agonz250
 *  Partner(s) Name:  
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	//Makes all port A's input pins as inputs; initalized to 1s
	DDRB = 0xFF; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;	//Makes all port B's input pins as outputs; initalized to 0s

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00; 
	unsigned char tmpC = 0x00;

	/* Insert your solution below */
    	while (1) {
		//1.)read inputi
		tmpA = PINA;
		
		//2.) perform computation
		//upper nibble of A to lower nibble of B 
		tmpB = ( (tmpA & 0xF0) >> 4) | (tmpB & 0xF0);

		//lower nibble of A to upper nibble of C
		tmpC = ((tmpA & 0x0F) << 4) | (tmpC & 0x0F);

		//3.) Write Output
		PORTB = tmpB; 
		PORTC = tmpC;
    	}
    	return 1;
}
