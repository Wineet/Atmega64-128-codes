;
; scan_bit.asm
;
; Created: 08-03-2019 13:59:29
; Author : desd
;
;scan bit from port

; Replace with your application code

.dseg
.org 0x100;

.cseg
.org 0x000




       LDI    R16, low(RAMEND)		// stack pointer initialisation is must other wise won;t work
                OUT    SPL, R16
                LDI    R16, high(RAMEND)
                OUT    SPH, R16


;
ldi r18, 0xff ;
out ddrc,r18 ;

ldi r18, 0x00;
out ddrd,r18; // Setting port as input port

start:

ldi r18, 0xFF ;
out portc,r18 

in r20,pind
out portc,r20

rjmp start


ldi r18, 0xff ;
out ddrc,r18 ;
ldi r18, 0xaa ;
out portc,r18 ;

end: rjmp end
