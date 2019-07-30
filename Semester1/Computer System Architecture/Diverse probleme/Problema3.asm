bits 32 
global start        
extern exit               
import exit msvcrt.dll    
segment data use32 class=data
    
;Se da un sir S de dublucuvinte. 
;Sa se obtina sirul D format din octetii dublucuvintelor din sirul D sortati in ordine crescatoare in interpretarea fara semn.
;Exemplu:
s dd 12345607h, 1A2B3C15h
;d db 07h, 12h, 15h, 1Ah, 2Bh, 34h, 3Ch, 56h
l equ $ - s ; lungimea sirului s 
d times l db 0 ; rezerv spatiu
aux db 0

segment code use32 class=code
    
start:
        
        mov ecx, l  
        mov edx, 0
        mov esi, s ; adresa lui s 
        repeta:
            lodsb ; in al am octetu
            mov [d+edx], al
            inc edx
        loop repeta
            
        ; si acuma mai trebuie sa sortez sirul d ! 
        ; bubble sort
        
        mov edx, 0 ; pe post de " ok " 
    whilee:  
            mov edx, 1 ; ok = 1 
            mov ecx, l - 1
            mov esi, 0     
        bucla:
    
            mov ah,[d+esi] ; v[i] 
            mov bh,[d+esi+1] ; v[i+1]
            
            cmp ah,bh ; 
            jbe nu_schimb ;
                mov [d+esi], bh
                mov [d+esi+1],ah
                mov edx, 0
                 
            nu_schimb: ; else continue;   
                inc esi
        loop bucla
    cmp edx, 0
        je whilee
            

        push    dword 0      
        call    [exit]
