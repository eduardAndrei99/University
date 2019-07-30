bits 32
global start        
extern exit   
extern printf
import printf msvcrt.dll          
import exit msvcrt.dll    
segment data use32 class=data

    ;(a+d-c)-(b+b)
    ; toate sunt byte
    a db 4
    b db 1
    c db 2
    d db 2
    mesaj db "Rezultat: %d", 10, 13
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov ebx, 0
        mov ah, 0 
        mov al, [a] ; ax = a
        add ax, [d] ; ax += d
        sub ax, [c] ; ax -= c
        ; ... ax -> (a + b - c)
        
        mov bh, 0
        mov bl, [b] ; bx = b
        add bx, [b] ; bx += b
        ; ... bx -> (b + b)
        sub ax, bx ; ax -= bx
        mov ah, 0
        
        push EAX
        push dword mesaj
        call [printf]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call [exit]     ; call exit to terminate the program
