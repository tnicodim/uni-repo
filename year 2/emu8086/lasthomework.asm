.data   
msg DB ?
.code
main proc  
    
 MOV AX, @data
 MOV DS, AX   
 mov ah,1
 int 21h 
 sub al,30h
 mov bl,al 
 mov dl,10
 mov ah,2
 int 21h
 mov dl, 8
 int 21h
 
input: mov ah,1
    int 21h
    cmp al,13
    je newword
    mov [si],al
    inc si
    jmp input
    
newword:
mov [si],' '
inc si
inc bh
cmp bh,bl
mov dl,10
mov ah,2
int 21h
je endofread
jmp input

newwordprint:
mov dl,10
mov ah,2
int 21h 
mov dl,13
int 21h
inc di
jmp loadsi
    
endofread: mov [si],'$'
    mov di,offset msg
    mov dl,13
    mov ah,2
    int 21h
    mov dl,10
    mov ah,2
    int 21h 
    mov bh,0
    
skipword:    
cmp [di],' '
je skipped
cmp [di],'$'
je final
inc di
jmp skipword
skipped:
inc di
jmp loadsi
print: cmp [di],'$'
    je final
    cmp [di],' '
    je newwordprint
    mov dl,[di]
    mov ah,2
    int 21h
    inc di
    jmp print
 
loadsi:
inc bh
mov al,bh
cmp bl,al
jl final 
mov si, offset msg
mov bp, di
jmp check
 
loaddi:
inc dh
mov di,bp
jmp print
    
check:
cmp [si],' '
je loaddi
mov al, [si]
cmp [di],al
jne skipword
inc si
inc di
jmp check

final:   
add dh,30h
mov dl,dh
int 21h 

main endp

end




