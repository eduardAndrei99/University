bits 32
global start        
extern exit 
extern printf   
import printf msvcrt.dll  
import exit msvcrt.dll 
segment data use32 class=data
    ; ...
    a db 5
    b dd 10
    c dq 10
    mesaj db "Rezultat: %d", 10, 13
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov al, [a]
        cbw ;al(a) -> ax
        mov bx, ax ; bx <- a
        mov ax, word [b]
        mov dx, word [b + 2]
        idiv bx ;ax -> cat
        
        cwde
        cdq
        mov ebx, dword [c]
        mov ecx, dword [c + 4]
        
        add eax, ebx
        adc edx, ecx ; edx : eax
        ;print
        push eax
        push dword mesaj
        call [printf]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
