Name: lab8palindrom
.model small
.data
msg db ?
msg2 db ?
L1 db ?
L2 db ?
aux db 0
aux2 db 0
.code
main proc
 MOV AX, @data
 MOV DS, AX   
 
input: mov ah,1
    int 21h
    cmp al,13 ; daca introducem enter => jump
    je endofread
    mov [si],al
    inc si
    jmp input

endofread: mov [si],'$'
    mov di,offset msg
    mov dl,10
    mov ah,2
    int 21h
    
 MOV SI,OFFSET msg
 
 endofstring:
    MOV AX, [SI]
    CMP AL, '$'
    JE loadnew
    INC SI
    JMP endofstring
    
 loadnew:
 MOV DI,OFFSET msg
 DEC SI
 
 checkpalindrome:
     CMP SI, DI
     JL pal
     MOV AX,[SI]
     MOV BX, [DI]
     CMP AL, BL
     JNE npal
 
    DEC SI
    INC DI
    JMP checkpalindrome

pal:
   mov dl,10
    mov ah,2
    int 21h
     mov dl,'p'
    int 21h
    jmp last
npal:
 mov dl,10
    mov ah,2
    int 21h
     mov dl,'n'
    int 21h
    jmp last
last: mov ah,4ch
    int 21h
main endp

end




