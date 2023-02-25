Name: temasapt4
.model small
.data 
 A DB 0
 B DB 0
 C DB 0
 D DB 0
 R1 DB ?
 R2 DB ?
 R3 DB ?
 R4 DB ?
 R5 DB ?
.code
main proc
 MOV AX, @data
 MOV DS, AX
  ; citirea primului numar de la tastatura
 MOV AH, 1
 INT 21H
 SUB AL, 30h
 MOV A, AL 
 
  mov dl, ' '
  mov ah, 2
  int 21h
  
; citirea celui de-al doilea numar de la tastatura
 MOV AH, 1
 INT 21H
 SUB AL, 30h
 MOV B, AL   
 
  mov dl, ' '
  mov ah, 2
  int 21h  
  
  
; citirea celui de-al treilea numar de la tastatura
 MOV AH, 1
 INT 21H
 SUB AL, 30h
 MOV C, AL 
 
 mov dl, ' '
 mov ah, 2
 int 21h
  
; citirea celui de-al 4-lea numar de la tastatura 
 MOV AH, 1
 INT 21H
 SUB AL, 30h
 MOV D, AL  
 
 mov dl, ' '
  mov ah, 2
  int 21h
  
; A + B - C
 MOV AL, A 
 ADD AL, B
 SUB AL, C
 MOV R1, AL
; A + A + A
MOV AL, A
ADD AL, A
ADD AL, A
MOV R2, AL
; A + C - B
MOV AL, A
ADD AL, C
SUB AL, B
MOV R3, AL
; A - C - B
MOV AL, A 
SUB AL, B
SUB AL, C
MOV R4, AL
; A + D - C + B
MOV AL, A
ADD AL, D
SUB AL, C
ADD AL, B
MOV R5,AL
;printare
  
 mov dl, 10
 mov ah, 2
 int 21h
 MOV DL, R1
 ADD DL, 30h
 INT 21H
 
 mov dl, ' '
 mov ah, 2
 int 21h
 MOV DL, R2
 ADD DL, 30h
 INT 21H
 
 mov dl, ' '
  int 21h
 MOV DL, R3
 ADD DL, 30h
 INT 21H
 
 mov dl, ' '
 int 21h
 MOV DL, R4
 ADD DL, 30h
 INT 21H
 
 mov dl, ' '
 int 21h
 MOV DL, R5
 ADD DL, 30h
 INT 21H
main endp
end 