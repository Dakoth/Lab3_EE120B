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
	DDRC = 0xFF; PORTC = 0x00;	//Makes all port B's input pins as outputs; initalized to 0s

	unsigned char tmpA = 0x00; 
	unsigned char tmpC = 0x00;

	unsigned char tmpABelt;

	/* Insert your solution below */
    	while (1) {
		//1.)read inputi
		tmpA = PINA & 0x0F; //Bottom nibble of tmpA 
		
		//2.) perform computation
		if ( tmpA > 0) { //If 1 or 2, PC5 lights up  
			tmpC = tmpC | 0x20; 
		} 
		if ( tmpA > 2 ) { //if 3 or 4, PC5 and PC4 light up  
			tmpC = tmpC | 0x10;
		}
		if ( tmpA > 4 ) { //if 5 or 6, PC5-PC3 on 
			tmpC = tmpC | 0x08;
		}
		if ( tmpA > 6 ) { //7-9, PC5-PC2
			tmpC = tmpC | 0x04;
		}
		if ( tmpA > 9 ) { //10-12, PC5-PC1
			tmpC = tmpC | 0x2;
		}
		if ( tmpA > 12 ) { //13-15, PC5-PC0
			tmpC = tmpC | 0x01;
		}
		
		//If tmp < 5,, light up PC6			
		if( tmpA < 5 ) { 
			tmpC = tmpC | 0x40;
		}
		else {	//Else keep everything the same 
			tmpC = tmpC & 0xBF;
		}

		//Part 3
		tmpABelt = PINA & 0xF0; //top nibble 

		//PC7 = 1 when PA4 = 1 (key in), PA5= 1 ( driver seated), and PA6 = 0 (seatbelt not fastened)
		//if ( (tmpA & 0xF0) == 0x30) { //changed to 0xF0 from 0x70
		if (tmpABelt == 0x30) {
			tmpC = tmpC | 0x80; 
		}
		else {	//else change nothin 
			tmpC = tmpC & 0x7F; 
		}
		//3.) Write Output 
		PORTC = tmpC;
    	}
    	return 1;
}
