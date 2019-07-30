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
 
segment data use32 class=data
    
    format db "%d", 0
     ok dd 1
     n dd 0 
   
segment code use32 class=code
    start:
       
       repp:
        push n
        push format
        call [scanf]
        add esp, 8

        mov eax, [n]
        ;mov ax, 19
        dec eax
        mov ecx, eax
        inc eax
        mov dword [ok], 1
        repeta:
            cdq
            div ecx 
            cmp edx, 0
            jne next
            mov dword [ok], 0
            next:
            mov eax, [n]
            ;mov ax, 19
        dec ecx
        cmp ecx, 1
        jne repeta
        
        push dword [ok]
        push format
        call [printf]
        add esp, 8
        
        cmp dword [n], 0
        jne repp
       
       push    dword 0
       call    [exit]