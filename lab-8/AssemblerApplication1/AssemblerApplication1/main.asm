
.include "m2560def.inc"

.def razr1 = r17
.def razr2 = r18
.def razr3 = r19
.def temp = r16


.cseg 
.org $0000 
jmp Reset
.org $0054			
rjmp TIMER4_COMPA

Reset:
	 ldi temp, high(RAMEND) 
	 out sph, temp
	 ldi temp, low(RAMEND)
	 out spl, temp


	 ldi temp, 0xff
	 out DDRC, temp

	 ldi temp, 0xff
	 sts DDRK, temp

	 ldi temp, 0xff
	 out DDRB, temp

	 ldi temp, 0x00
	 out DDRA, temp

	 ldi temp, 0xff
	 out PORTA, temp

	 cli
	 ldi temp, 0x00
	 out TCCR4A, temp1
	 ldi temp, (1 << WGM42) | (1 << CS42) | (1 << CS40)
	 out TCCR4B, temp
	 ldi temp, (1 << OCIE4A)	
	 out TIMSK4, temp
	 ldi temp, 0b0000_1101	
 	 out OCR4AH, temp
	 ldi temp, 0b0000_0000	
	 out OCR4AL, temp
	 sei





start:
    ldi temp, 0b00000000
	out PORTC, temp

	ldi temp, 0b00000000
	sts PORTK, temp

	in temp, PINA
	andi temp,(1<<PA6)|(1<<PA4)
	cpi temp,(0<<PA6)|(1<<PA4)
	breq Algo1
	cpi temp,(1<<PA6)|(0<<PA4)
	breq Algo2

    rjmp start

Algo1:
    ldi temp, 0xff
    out PORTB, temp
	rcall Delay
	ldi temp, 0x00
    out PORTB, temp

	ldi temp, 0b10000001
	out PORTC, temp
	rcall Delay

	ldi temp, 0b01000010
	out PORTC, temp
	rcall Delay

	ldi temp, 0b00100100
	out PORTC, temp
	rcall Delay

	ldi temp, 0b00011000
	out PORTC, temp
	rcall Delay
	rjmp start




Algo2:
    ldi temp, 0xff
    out PORTB, temp
	rcall Delay
	ldi temp, 0x00
    out PORTB, temp

	ldi temp, 0b10000000
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b01000000
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b00100000
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b00010000
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b00001000
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b00000100
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b00000010
	sts PORTK, temp
	rcall Delay

	ldi temp, 0b00000001
	sts PORTK, temp
	rcall Delay
	rjmp start

Delay:
	ldi razr1, 255
	ldi razr2, 255
	ldi razr3, 30
	PDelay:
		dec razr1
		brne PDelay
		dec razr2
		brne PDelay
		dec razr3
		brne PDelay
		ret
		

