Name: lab8
.model small
.data
msg DW ?
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
    mov dl,13
    mov ah,2
    int 21h
    mov dl,10
    mov ah,2
    int 21h

print: cmp [di],'$'
    je last
    cmp [di],32
    mov dl,[di]
    sub dl,32
    mov ah,2
    int 21h
    inc di
    jmp print


last: mov ah,4ch
    int 21h

main endp

end




