.model small
.data

num1 db 14
num2 db 8
sum db 0
dif db 0

.code
main proc
     MOV ax,@data 
     MOV ds,ax
     MOV al,num1
     ADD al,num2
     MOV sum,al
     MOV al,num1
     SUB al,num2
     MOV dif,al
   main endp
end     