bits 32
global start        
extern exit              
import exit msvcrt.dll

;Problema 1 lab 5
segment data use32 class=data
    ; Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte produsul dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S. 
    s db 1, 2, 3, 4
    l equ $-s; lungimea sirului
    d times l-1 dw 0

segment code use32 class=code
    start:
      mov ecx, 3
      mov esi, 1 
      jecxz final
      
      repeta:
        mov al, [s+esi] 
        mov bl, [s+esi-1]
        imul bl; ax -> inmultirea
        mov [d+esi*2], ax 
        inc esi
       loop repeta  
      
    final:
    
        ; exit(0)
        push    dword 0
        call    [exit]       
