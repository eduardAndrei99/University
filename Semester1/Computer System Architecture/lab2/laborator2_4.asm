bits 32
global start        
extern exit    
extern printf
import printf msvcrt.dll          
import exit msvcrt.dll 
segment data use32 class=data
    ; ...
    ;(d-b*c+b*2)/a
    ; a, b, c byte d word
    a db 2
    b db 1
    c db 2
    d dw 3
    doi db 2
    mesaj db "Rezultat: %d", 10, 13

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov ebx, 0
        mov ah, 0
        mov al, [b]
        mul BYTE [c] ; ax = al * [c]
        ;...    ax = b * c
        mov bx, ax
        ;... bx = b *c
        mov ah, 0
        mov al, [b]
        mul BYTE [doi] ; ax = b * 2
        sub ax, bx ; ax = -b*c + b*2
        add ax, [d] ; (d-b*c+b*2)
        div BYTE [a] ; (d-b*c+b*2) = 1
   
        ; afisam continutul registrului EAX
        mov ah,0
        push EAX
        push dword mesaj
        call [printf]
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
