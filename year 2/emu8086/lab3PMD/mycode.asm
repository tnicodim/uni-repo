Name: Aritmetic1
.model small ; prin aceasta instruc?iune se selecteaza modelul de memorie folosit
.data ; reprezinta sec?iunea de declarare a datelor
 A DB 0
 B DB 0
 C DB 0
 X DW 7
.code ; reprezinta sec?iunea în care se scrie codul sursa al programului
main proc ; proc este cuvântul cheie pentru începerea unei proceduri
 MOV AX, @data ; instruc?iuni implicite pentru încarcarea segmentului de date
 MOV DS, AX
  ; citirea primului numar de la tastatura
 MOV AH, 1 ; serviciu de citire asociat întreruperii INT 21H – Keyboard input with echo
 INT 21H
 MOV A, AL
; citirea celui de-al doilea numar de la tastatura
 MOV AH, 1
 INT 21H
 MOV B, AL
; citirea celui de-al treilea numar de la tastatura
 MOV AH, 1
 INT 21H
 MOV C, AL
; calculul sumei A + B
 MOV AL, A ; primul numar A este mutat în registrul AL pe 8 bi?i
 ADD AL, B ; rezultatul sumei A+B se afla în registrul AL pe 8 bi?i
; scaderea lui C din rezultat
 SUB AL, C
; afi?area rezultatului pe ecran
 MOV AH, 2 ; serviciu de afi?are asociat întreruperii INT 21H – Display output
 MOV DL, AL ; rezultatul este copiat în registrul DL
 INT 21H
main endp ; endp este cuvântul cheie care semnifica finalul unei proceduri
end 