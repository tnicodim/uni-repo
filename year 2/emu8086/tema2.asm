Name: tema2
;pentru orice x citit de la tastatura sa se faca suma
;de la 0 pana la x in acord cu functia de mai jos.
.model small
.data
R DW 0
F DB 0
X DB ?
.code
main proc
 MOV AX, @data
 MOV DS, AX
;citire 
 MOV AH, 1
 INT 21H
 SUB AL, 30H
 MOV X, AL
 MOV AH, 2
 MOV DL, ' '
 INT 21h
 INC X
;3-way function (while{if elif else})
 LBL_WHILE:
 DEC X
 MOV AL, X 
 CMP AL, 0FFh ;if AL = 0x0 - 0x1 = 0xFF -> jump FINAL
 JZ FINAL
 ;if X>=6 jmp if, if x>=3 jmp elif, else jmp else
 CMP AL, 6
 JGE LBL_IF
 CMP AL, 3
 JGE LBL_ELIF
 JMP LBL_ELSE
 LBL_IF:
 MOV AX,R
 ADD AX,2
 MOV R,AX
 JMP LBL_WHILE
 LBL_ELIF:
 MOV AX,2
 MUL X
 MUL X
 MUL X
 ADD AX,R
 MOV R,AX
 JMP LBL_WHILE
 LBL_ELSE:
 MOV AX, 3
 MUL X
 MUL X
 ADD AX, 2
 MOV BX, AX
 MOV AX, 6
 MUL X
 ADD AX,BX
 ADD AX,R
 MOV R,AX
 JMP LBL_WHILE
 FINAL: 
;printare
MOV AH, 2 
MOV DX, R
INT 21H
main endp
end