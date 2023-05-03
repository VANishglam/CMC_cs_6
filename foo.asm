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
    
    fld1
    fldl2e
    fld qword[esp]
    fmulp
    f2xm1
    faddp
    
    add esp, 8
    mov esp, ebp
    pop ebp
    ret

f2:
    push ebp
    mov ebp, esp
    sub esp, 8
    
    fld ng_two
    fld qword[esp]
    fmulp
    fld qword[eight]
    faddp
    
    add esp, 8
    mov esp, ebp
    pop ebp
    ret

f3:
    push ebp
    mov ebp, esp
    sub esp, 8
    
    fld ng_five
    fld qword[esp]
    fdivp
    
    add esp, 8
    mov esp, ebp
    pop ebp
    ret