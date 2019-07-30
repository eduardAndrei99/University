; Codul de mai jos va afisa mesajul ”n=”, apoi va citi de la tastatura valoarea numarului n.
bits 32
global start        
; declararea functiilor externe folosite de program
extern exit, printf, scanf ; adaugam printf si scanf ca functii externa            
import exit msvcrt.dll    
import printf msvcrt.dll    ; indicam asamblorului ca functia printf se gaseste in libraria msvcrt.dll
import scanf msvcrt.dll     ; similar pentru scanf
                          
segment data use32 class=data
	n dd  0  
    ; sirurile de caractere sunt de tip byte
	message  db "n = ", 0  ; sirurile de caractere pentru functiile C trebuie sa se termine cu valoarea 0 (nu caracterul)
	format  db "%d", 0  ; %d <=> un numar decimal (baza 10)
    format_print db "Numarul minim este %d ", 0
    ;Se citesc de la tastatura numere (in baza 10) pana cand se introduce cifra 0. Determinaţi şi afişaţi cel mai mic număr dintre cele citite.
segment code use32 class=code
    start:
    
       mov ebx, 0ffffh
       
       repeta:
        push dword message ; ! pe stiva se pune adresa string-ului, nu valoarea
        call [printf]      ; apelam functia printf pentru afisare
        add esp, 4*1       ; eliberam parametrii de pe stiva ; 4 = dimensiunea unui dword; 1 = nr de parametri
                                                   
        ; vom apela scanf(format, n) => se va citi un numar in variabila n
        ; punem parametrii pe stiva de la dreapta la stanga
        push dword n       ; ! adresa lui n, nu valoarea
         push dword format
        call [scanf]       ; apelam functia scanf pentru citire
        add esp, 4 * 2     ; eliberam parametrii de pe stiva
        
        cmp dword [n],0
        je afisaree
        
        cmp ebx, dword [n]
        jl nu_schimb
        mov ebx,[n]
        
        nu_schimb:
        
        cmp dword [n],0
        jnz repeta
        
        afisaree:
        push dword ebx
        push dword format_print ; ! pe stiva se pune adresa string-ului, nu valoarea
        call [printf]      ; apelam functia printf pentru afisare
        add esp, 4 * 2     ; eliberam parametrii de pe stiva; 4 = dimensiunea unui dword; 2 = nr de parametri
        
        ; exit(0)
        push dword 0      ; punem pe stiva parametrul pentru exit
        call [exit]       ; apelam exit pentru a incheia programul