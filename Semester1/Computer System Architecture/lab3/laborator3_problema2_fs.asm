bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
segment data use32 class=data
    ; ...
    ;x+(2-a*b)/(a*3)-a+c; a-byte; b-word; c-doubleword; x-qword
    a db 3
    b dw -4
    c dd -1
    x dq -12
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov ebx, 0
        mov al, [a] ;
        mov dl, 3
        imul dl ; al = a * 3
        cbw ; ax = a * 3
        mov bx, ax ; bx = a * 3
        
        xor eax, eax ; eax = 0
        mov al, [a]
        cbw
        imul word [b]; ax -> a * b  
        xor dx, dx
        mov dx, 2
        sbb dx, ax
        mov ax, dx ; ax -> (2 - a * b)
        cwd ; dx : ax -> (2 - a * b)
        idiv bx ; ax -> (2 - a * b) / (a * 3)
        xor bx, bx
        mov bl, [a]
        sbb ax, bx ;ax -> (2 - a * b) / (a * 3) + a
        mov ebx, [c]
        add eax, ebx ;eax -> (2 - a * b) / (a * 3) + a - c
        cdq; eax -> edx : eax 
        
        add eax, dword[x]
        adc edx, dword[x+4]
          
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
