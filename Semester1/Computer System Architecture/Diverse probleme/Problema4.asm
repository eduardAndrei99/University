bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll

segment data use32 class=data
    ; ...
    sir db 1,2,3,4
    l equ $ - sir
    s db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov dl, 1
        mov ecx, [l]
        mov esi, 0
        mov bl, 2
        repeta:
            mov al, [sir+esi]
            cbw
            idiv bl
            cmp ah, 0
            je par  
            jne impar
                par:
                    inc esi
                    jecxz final
                    loop repeta
                impar:
                    add dl, al
                    mov [s], dl
                    inc esi
                    jecxz final
                    loop repeta
        final:
        mov [s], dl
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
