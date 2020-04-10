/*	Author: agonz250
 *  Partner(s) Name:  
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise # 1
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
	DDRB = 0x00; PORTB = 0xFF; 	// similar to port A but for B
	DDRC = 0xFF; PORTC = 0x00;	//Makes all port C's input pins as outputs; initalized to 0s

	unsigned char tmpA = 0x00; 
	unsigned char tmpB = 0x00;

	unsigned char numA = 0; //number of 1s in A
	unsigned char numB = 0; //number of 1s in B

	/* Insert your solution below */
    	while (1) {
		//1.)read inputi
		tmpA = PINA; 
		tmpB = PINB;
 
		////2.) perform computation
		numA = ((tmpA & 0x80) >> 7) + ((tmpA & 0x40) >> 6) + ((tmpA & 0x20) >> 5) + 
		       ((tmpA & 0x10) >> 4) + ((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) + ((tmpA & 0x02) >> 1) + (tmpA & 0x01);


		numB = ((tmpB & 0x80) >> 7) + ((tmpB & 0x40) >> 6) + ((tmpB & 0x20) >> 5) + 
		       ((tmpB & 0x10) >> 4) + ((tmpB & 0x08) >> 3) + ((tmpB & 0x04) >> 2) + ((tmpB & 0x02) >> 1) + (tmpB & 0x01);
				
		//3.) Write Output 
		PORTC = numA + numB;
    	}
    	return 1;
}
