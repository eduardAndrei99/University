bits 32                         
segment code use32 public code
global f

f:
	mov esi,0
    mov edi,1
    mov ecx, [esp+4]
     repeta:
        mov eax, [esp+12]
        mov dh, [eax+edi]
        
        mov eax, [esp+8]
        mov bh, [eax+esi]
        mov eax, [esp+16] 
        mov [eax+edi],dh
        mov [eax+esi],bh
        inc esi
        inc esi
        inc edi
        inc edi
     loop repeta
	
	ret 16