bits 32
global start        
extern exit 
extern printf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
segment data use32 class=data
    ; ...
    ;(c+d)+(a-b)+a
    ; a, b, c, d - word
    a dw 3
    b dw 2
    c dw 1
    d dw 1
    mesaj db "Rezultat: %d", 10, 13
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov ebx, 0
        mov ax, [c]
        add ax, [d]
        mov bx, [a]
        sub bx, [b]
        add ax, bx
        add ax, [a]
    
        push EAX
        push dword mesaj
        call [printf]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
