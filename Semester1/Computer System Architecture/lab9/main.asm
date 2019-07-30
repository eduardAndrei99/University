bits 32
global start
import printf msvcrt.dll
import exit msvcrt.dll
extern printf, exit
extern f,g

segment data use32
	
    a db "abcdefzmihai",0
    lg equ ($-a)/2
    rez times lg*2 db '0'
    b db "badcfeqiahim",0
    format db "%s"
    spatiu db 0Ah,0
    formatD db "%d"

segment code use32 public code
start:
	
    push rez
    push a
    push b
    push lg

    call f
    
    mov byte [rez+lg*2],0
        push dword rez
        push dword format
        call [printf]
        add esp, 4*2
        
    push rez
    push a
    push b
    push lg
    
    call g
     
     mov byte [rez+lg*2],0
        push dword rez
        push dword format
        call [printf]
        add esp, 4*2
     
     
	push 0
	call [exit]
