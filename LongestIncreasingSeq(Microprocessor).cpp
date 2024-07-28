.model small
.stack 100h 
.code    
 
main proc
  
   
   mov ah,1     
   mov cl,'1'
   int 21h
   mov bl,al 
   mov bh,'1'
   
   while:
   cmp al,0DH
   je done 
   
   int 21h 
   inc bl
   cmp bl,al   
   je nxt 
   jmp another
   nxt:
   inc cl
   mov bl,al
   cmp cl,bh
   jg nxt1 
   jmp nxt2
   nxt1:
   mov bh,cl     
   jmp nxt2
   
   another:  
   mov cl,'1'
   mov bl,al
   nxt2: 
   jmp while
   
   done:  
   mov ah,2
   mov dl,10
   int 21h
   mov dl,13
   int 21h
   mov dl,bh
   int 21h
   
 
  
   
  
  
   
    
    
  
       
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
     

exit: 
mov ah,4ch
int 21h
main endp
end 
