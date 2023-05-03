section .rodata
two dq 2.0
eight dq 8.0
ng_two dq -2.0
ng_five dq -5.0
section .text
global f1, f2, f3

f1:
    push ebp
    mov ebp, esp
    sub esp, 8
    
    fld1          ; 1
    fld qword[esp]; x
    fprem1        ; {x}
    fldl2e        ; log_2_e
    fmulp         ; {x} * log_2_e
    f2xm1         ; 2 ^ ({x} * log_2_e) - 1
    fld1          ; 1
    faddp         ; 2 ^ ({x} * log_2_e)
    
    
    add esp, 8
    mov esp, ebp
    pop ebp
    ret

f2:
    push ebp
    mov ebp, esp
    sub esp, 8
    
    fld ng_two      ; -2
    fld qword[esp]  ; x
    fmulp           ; -2 * x
    fld qword[eight]; 8
    faddp           ; -2 * x +8
    
    add esp, 8
    mov esp, ebp
    pop ebp
    ret

f3:
    push ebp
    mov ebp, esp
    sub esp, 8
    
    fld ng_five     ; -5
    fld qword[esp]  ; x
    fdivp           ; -5 / x
    
    add esp, 8
    mov esp, ebp
    pop ebp
    ret