Name: temasapt5_1_fibonacci
.model small
.data
A DB 0
B DB 1
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
 
 MOV DL, 1
 ADD DL, 30h
 INT 21H
 MOV DL, ' '
 INT 21h
 
 MOV CL, N
 LBL_FOR:
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
 LOOP LBL_FOR 
 
 
main endp
end     
    




