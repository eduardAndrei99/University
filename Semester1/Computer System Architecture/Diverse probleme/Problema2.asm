bits 32
global start        
extern exit      
import exit msvcrt.dll
extern fopen,fclose,fprintf,printf,scanf
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll

;Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura numere si sa se scrie valorile citite in fisier pana cand se citeste de la tastatura valoarea 0. 
 
segment data use32 class=data
    numeFisier db "prob12.txt", 0
    descriptorFisier dd -1
    modAcces db "w", 0
    spatiu dd 20h
    format db "%d", 0
    formatSpatiu db "%c", 0
    n dd 0
    
segment code use32 class=code
    start:
        
        ; eax = fopen(numeFisier, modAcces);
        push modAcces
        push numeFisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptorFisier], eax 
        ; fprintf(descriptor_fis,format,var)
        
       repeta:
            push n
            push format
            call [scanf]
            add esp, 8
            push dword [n]
            push format
            push dword [descriptorFisier]
            call [fprintf]
            push dword [spatiu]
            push dword formatSpatiu
            push dword [descriptorFisier]
            call [fprintf]
            add esp, 12
            cmp dword [n], 0
            jne repeta

        push    dword 0 
        call    [exit]  