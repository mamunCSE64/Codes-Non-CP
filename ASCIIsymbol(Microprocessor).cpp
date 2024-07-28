   .model small
   .stack 100h
   .data
a db 9
.code    

   main proc 
        mov ax,@data
        mov ds,ax
        
        mov cx,128
        mov bx,128
        
        Level: 
          
        mov ah,2   
        mov dx,bx 
        int 21h  
        
        cmp a,0
        jz NL
        jmp nxt
        
        NL:
        mov dl,10
        int 21h
        mov dl,13
        int 21h
        mov a,9
       
        nxt:
        inc bx   
        dec a
             
        Loop Level    
        
        
         
        
        
     
    
    
            
      
    
    
    
   
   
   
   
   
   
   
   
   
   
        
    exit:
    mov ah,4ch
    int 21h
    main endp
end main
