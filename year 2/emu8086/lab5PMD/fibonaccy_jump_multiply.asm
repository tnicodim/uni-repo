Name: fibonacci_jump_multiplication
.model small
.data
A DB 1
B DB 0
R DB ?
N DB 5
M DW 1
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
 MOV AH, 2
 INT 21H
 MOV DL, ' '
 INT 21h 
 MOV BL, R
 MOV AX, M
 MOV AH,0
 MUL BL
 MOV M, AX
 MOV AL, N
 SUB AL, 1
 MOV N, AL
 
 JGE K1
 
 MOV AH, 2
 MOV DL, 10
 INT 21h
 
 MOV AH, 0 
 MOV DX, M
 INT 21h
 
 
 
main endp
end     
    




