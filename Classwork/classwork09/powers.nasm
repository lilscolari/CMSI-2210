section .data
    format db "Power of 2: %d", 10, 0;

section .text
    extern _printf;
    global _main;

_main: mov eax, 1;
    mov ecx, 0;
    mov ebx, 1000000;

loop: mov edx, ecx;

power_calc: cmp edx, 0;
    je print_result;
    imul eax, 2;
    dec edx;
    jmp power_calc;

print_result: push eax;
    push format;
    call _printf;
    add esp, 8;
    cmp eax, ebx;
    jge done;
    inc ecx;
    jmp loop;

done: xor eax, eax;
    ret;
