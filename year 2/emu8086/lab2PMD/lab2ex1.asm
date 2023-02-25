.model small
.data
c EQU 8
var1 db 4
var2 db ?
.code
main proc
    MOV ax,@data 
    MOV ds,ax
    MOV var2,c
    MOV al,var1
    MOV ah,var2
    main endp
end