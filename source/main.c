/*	Author: agonz250
 *  Partner(s) Name:  
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise # 5
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
	DDRD = 0x00; PORTD = 0xFF;	//Makes all port A's input pins as inputs; initalized to 1s
	DDRB = 0xFE; PORTB = 0x00;	//Makes every pin except P0 as an output. P0 is an input

	unsigned char tmpD; //= 0x00;
	unsigned char tmpB;// = 0x00; 
	
	unsigned short weight = 0;

	/* Insert your solution below */
    	while (1) {
		//1.)read input
		tmpD = PIND;
		tmpB = PINB & 0x01; 	//only uses B0 as an input 
		
		//2.) perform computation
		
		//If B0 has a weight value
		if (tmpB == 0x01) {
			weight = 1;
		}

		int i = 0;
		int x = 2;	
	
		//Finds sum of all 8 bits of B
		while (i < 8) {
			if (( ( tmpD >> i) & 0x01) == 0x01) {
				weight = weight + x;
			}
			x = x * 2;
			++i;
		}
			

		//airbag settings
		if (weight >= 70) {
			tmpB = tmpB | 0x02;
			tmpB = tmpB & 0xFB;
		}
		else if ( weight < 70 && weight > 5) {
			tmpB = tmpB | 0x04;
			tmpB = tmpB & 0xFD;
		}
		else { 			//No passenger
			tmpB = 0x00;
		}
			
		//3.) Write Output
		PORTB = tmpB;
		//PORTC = tmpC;
    	}
    	return 1;
}
