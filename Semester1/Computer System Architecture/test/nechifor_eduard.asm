bits 32
global start        
extern exit,fopen,printf,fprintf,scanf,fread
import exit msvcrt.dll   
import fopen msvcrt.dll
import printf msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import fread msvcrt.dll
                         
segment data use32 class=data
    
    numeFisierIn db "in1.txt", 0
    numeFisierOut db "out1.txt", 0
    formatIntreg db "%d", 0
    descriptorIn dd -1
    descriptorOut dd -1
    modAccesIn db "r", 0
    modAccesOut db "w", 0
    formatString db "%s", 0
    i dd 0
    j dd 0
    len dd 100
    text times 100 db 0
    
segment code use32 class=code
    start:
    
        ;eax = fopen(nume_fisier, modAcces)
        push modAccesIn
        push numeFisierIn
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je sfarsit
        mov dword [descriptorIn], eax
        
        push modAccesOut
        push numeFisierOut
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je sfarsit
        mov dword [descriptorOut], eax
        
        push i 
        push formatIntreg
        call [scanf]
        add esp, 8
        
        push j 
        push formatIntreg
        call [scanf]
        add esp, 8
        
         ;eax = fread(text, 1, len, descriptor)
        push dword [descriptorIn]
        push dword 100
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        mov esi, dword [i]
        mov edi, dword [j]
        dec esi
        dec edi 
        mov al, [text + esi]
        mov bl, [text + edi]
        mov [text + esi], bl 
        mov [text + edi], al
        
        push dword text 
        push dword [descriptorOut]
        call [fprintf]
        add esp, 4*2

        sfarsit:
        push    dword 0 
        call    [exit]      
