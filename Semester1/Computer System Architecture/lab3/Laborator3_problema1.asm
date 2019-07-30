bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
segment data use32 class=data

    ; ...(a*b+2)/(a+7-c)+d+x; a,c-byte; b-word; d-doubleword; x-qword
    a db 2
    c db 3
    b dw 3
    d dd 4
    x dq 20
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov ebx, 0
        mov al, [a]
        add al, 7
        sbb al, [c]
        cbw ; ax->word -> a + 7 - c
        mov bx, ax ; bx-> a + 7 - c
        mov eax, 0
        mov al, [a]
        mul dword [b]
        add ax, 2
        cbw
        div bx ; ax ->(a*b+2)/(a+7-c)
        cwde
        add eax, [d]
        cdq ; edx : eax -> (a*b+2)/(a+7-c) +d
        mov ebx, dword [x] 
        mov ecx, dword [x+4]
        add eax, ebx
        adc edx, ecx
        ; Rezultatul este in edx eax
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
