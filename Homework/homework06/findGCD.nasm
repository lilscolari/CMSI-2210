global _main;
extern _printf, _scanf;

section .text;
    _main: push input_msg;
    call _printf;
    add esp, 4;
    push num_buffer + 4;
    push num_buffer;
    push format;
    call _scanf;
    add esp, 12;
    mov eax, [num_buffer];
    mov ebx, [num_buffer + 4];

    gcd_loop: xor edx, edx;
    div ebx;
    test edx, edx;
    jz gcd_done;
    mov eax, ebx;
    mov ebx, edx;
    jmp gcd_loop;

    gcd_done: mov [gcd], ebx;
    push dword [gcd];
    push output_msg;
    call _printf;
    add esp, 8;
    xor eax, eax;
    ret;

section .bss;
    num_buffer resd 2;
    gcd resd 1;

section .data;
    input_msg db "Enter two numbers: ", 0;
    output_msg db "GCD: %d", 0;
    format db "%d %d", 0;