/*	Author: agonz250
 *  Partner(s) Name:  
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise # 2
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

	/* Insert your solution below */
    	while (1) {
		//1.)read inputi
		tmpA = PINA; 
		
		//2.) perform computation
		if ( tmpA == 1 || tmpA == 2) { //If 1 or 2, PC5 lights up, pc6 on 
			tmpC = tmpC | 0x60; 
		} 
		else if ( tmpA == 3 || tmpA == 4 ) { //if 3 or 4, PC5 and PC4 light up, PC6 on  
			tmpC = tmpC | 0x70;
		}
		else if ( tmpA == 5 | tmpA == 6) { //if 5 or 6, PC5-PC3 on 
			tmpC = tmpC | 0x38;
		}
		else if ( tmpA == 7 || tmpA == 8 || tmpA == 9) { //7-9, PC5-PC2
			tmpC = tmpC | 0x3C;
		}
		else if ( tmpA == 10 || tmpA == 11 || tmpA == 12) { //10-12, PC5-PC1
			tmpC = tmpC | 0x3E;
		}
		else if ( tmpA == 13 || tmpA == 14 || tmpA == 15) { //13-15, PC5-PC0
			tmpC = tmpC | 0x3F;
		}
		
		//3.) Write Output 
		PORTC = tmpC;
    	}
    	return 1;
}
