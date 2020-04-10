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

	unsigned char tmpA, tmpB, tmpC;


	/* Insert your solution below */
    	while (1) {
		//1.)read input
		//2.) perform computation 
		//3.) Write Output 

    	}
    	return 1;
}
