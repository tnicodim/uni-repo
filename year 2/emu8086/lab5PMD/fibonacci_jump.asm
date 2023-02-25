Name: fibonacci_jump
.model small
.data
A DB 1
B DB 0
R DB ?
N DB 5
.code
main proc
 MOV AX, @data
 MOV DS, AX
 
 MOV AH, 2
 MOV DL, 0
 ADD DL, 30h
 INT 21H
 MOV DL, ' '
 INT 21h
 
K1:
 MOV AL, A
 ADD AL, B
 MOV R, AL
 MOV B, AL
 SUB AL,A
 MOV A,AL
 MOV DL, R
 ADD DL, 30h
 INT 21H
 MOV DL, ' '
 INT 21h
 MOV AL, N
 SUB AL, 1
 MOV N, AL
 
 JGE K1
 
 
 
main endp
end     
    




