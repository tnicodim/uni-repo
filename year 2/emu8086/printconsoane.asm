Name: printconsoane
.data
msg DB ?
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
    int 21h

print: cmp [di],'$'
    je last
    cmp [di], 'a'
    je skip
    cmp [di], 'e'
    je skip
    cmp [di], 'o'
    je skip
    cmp [di], 'u'
    je skip
    cmp [di], 'i'
    je skip
    jmp printconsoana
printconsoana:
    mov dl,[di]
    mov ah,2
    int 21h
skip:
    inc di
    jmp print
last:

main endp

end