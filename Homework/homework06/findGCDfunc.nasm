global _findGCDfunc;
extern _printf;

section .text;
    _findGCDfunc: mov eax, [esp + 4];
    mov ebx, [esp + 8];

    gcd_loop: xor edx, edx;
    div ebx;
    test edx, edx;
    jz gcd_done;
    mov eax, ebx;
    mov ebx, edx;
    jmp gcd_loop;

    gcd_done: mov eax, ebx;
    ret;