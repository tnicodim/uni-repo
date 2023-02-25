Name: temasapt4_2_sumaN
.model small
.data
N DB 3
R DB 0
.code
main proc
 MOV AX, @data
 MOV DS, AX
 MOV AL,0 
 
 MOV CL, N
 LBL_FOR:
 
 ADD R, 1
 ADD AL,R

 LOOP LBL_FOR 
 
 MOV AH, 2
 MOV DL, AL
 ADD DL, 30h
 INT 21H
 
main endp
end     
    




