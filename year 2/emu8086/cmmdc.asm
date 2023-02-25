org 100h

.data
       
a db 5
b db 21
cmmmc db ?    
cmmdc db ?

.code 
 
mov al, a
mov bl, b 

  
 
while:
     
    cmp al, bl
    je finish
    cmp al, bl
    jg if
    jmp else
    if:
    
        sub al,bl 
        jmp while
    else:
        
        sub bl, al
        jmp while
finish: 
 
mov cmmdc, al
mov al, a
mul b
div cmmdc
mov cmmmc, al 

 
ret