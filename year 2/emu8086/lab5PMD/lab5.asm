org 100h
Name: lab5
.model small
.data
A DB 8
B DB 2
C DB 5
; (A+B)/C
.code
main proc
 MOV AX, @data
 MOV DS, AX
 MOV AL,A
 ADD AL,B
 MOV BL,C
 MOV AH,0
 DIV BL        
 MOV DL,AL        
 ADD DL, 30h
 MOV AH, 2
 INT 21h
 
main endp
end     