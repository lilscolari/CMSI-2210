section .data
    format db "%d", 10, 0;

section .text
    extern _printf;
    global _main;

_main: xor eax, eax;
    mov ebx, 1;
    mov ecx, 10;

print_loop: push eax;
    push format;
    call _printf;
    add esp, 8;
    mov edx, eax;
    mov eax, ebx;
    add ebx, edx;
    dec ecx;
    jnz print_loop;
    mov eax, 0;
    ret;
