bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
; declare external functions needed by our program
extern exit  
extern printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
import printf msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll

segment data use32 class=data
    ; ...a*d*e/(f-5)
    ; a byte e word d byte f word
    a db 2
    d db 1
    e dw 2
    f dw 6
    mesaj db "Rezultat: %d", 10, 13
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        MOV EAX, 0
        MOV EBX, 0
        mov ah, 0
        mov al, [a]
        mul BYTE [d] ; ax -> a *d 
        mul WORD [e] ; dx :ax -> a*d*e
        mov bx, [f] ; bx = f 
        sub bx, 5 ; bx -= 5
        div bx ; dx : ax / bx
        ; exit(0)
        push eax
        push dword mesaj
        call [printf]
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
