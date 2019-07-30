bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dw 0111010111110101b
    b dd 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; bitii 28-31 ai lui B sunt 1;
        ; or cu masca
        
        xor ebx, ebx ; in bx vom avea rezultatul
        or ebx, 11110000000000000000000000000000b ; ebx -> 1111 0000000000000000000000000000b
        
        ;bitii 24- 25 si 26-27 ai lui B sunt bitii 8-9 ai lui A
        ;izolam bitii 8-9 ai lui a 
        ;folosind and 
     
        xor eax, eax ; eax -> 0
        mov eax, [a] ; eax -> 0000 0000 0000 0000 0111 0101 1111 0101b
        and eax, 00000000000000000000001100000000b 
                    ; eax -> 0000 0000 0000 0000 0000 0001 0000 0000b
                    ; trebuie sa aducem pe rand bitii 8-9 ai lui a pe pozitiile 24-25, iar apoi pe 26-27
        mov cl, 16
        shl eax, cl ;   eax -> 0000 0001 0000 0000 0000 0000 0000 0000b
        or ebx, eax ;or ebx -> 1111 0000 0000 0000 0000 0000 0000 0000b
                       ;ebx -> 1111 0001 0000 0000 0000 0000 0000 0000b
        mov cl, 2
        shl eax, cl ;   eax -> 0000 0100 0000 0000 0000 0000 0000 0000b
        or ebx, eax ;or ebx -> 1111 0001 0000 0000 0000 0000 0000 0000b
                       ;ebx -> 1111 0101 0000 0000 0000 0000 0000 0000b
        
        ;bitii 20-23 ai lui B sunt bitii 0-3 inversati ca valoare ai lui A ;
        xor eax, eax
        mov eax, [a] ; in eax il am pe a 
        and eax, 00000000000000000000000000001111b; izolez bitii 0-3 ai lui a 
        mov cl, 20
        shl eax, cl
        not eax
        and eax, 00000000111100000000000000000000b
        or ebx, eax ; ebx -> 1111 0101 1010 0000 0000 0000 0000 0000b
        
        ;bitii 16-19 ai lui B sunt biti de 0
        and ebx, 11111111111100001111111111111111b
        ; ebx -> 1111 0101 1010 0000 0000 0000 0000 0000b
        
        ;bitii 0-15 ai lui B sunt identici cu bitii 16-31 ai lui b
        xor eax, eax
        mov eax, ebx
        and eax, 11111111111111110000000000000000b
        mov cl, 16
        shr eax, cl ; 
        or ebx, eax ; ebx -> 1111 0101 1010 1111 0101 1010
        mov [b], ebx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
