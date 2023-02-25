Name: vocalaMARE
.model small
.data
msg DW ?
.code
main proc
 MOV AX, @data
 MOV DS, AX   
 
input: mov ah,1
    int 21h
    cmp al,13
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
    je finish
    cmp [di], 'a'
    je printvocala
    cmp [di], 'e'
    je printvocala
    cmp [di], 'o'
    je printvocala
    cmp [di], 'u'
    je printvocala
    cmp [di], 'i'
    je printvocala
    jmp printother
printvocala:
    mov dl,[di]
    sub dl,32
    mov ah,2
    int 21h
    inc di
    jmp print
printother:
    mov dl,[di]
    mov ah,2
    int 21h
    inc di
    jmp print
finish:

main endp

end




