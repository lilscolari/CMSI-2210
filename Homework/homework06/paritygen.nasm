global _main;
extern _printf, _atoi;

section .data
    output_msg db "Parity bit: %d", 0;

_main: push ebp;
    mov ebp, esp;
    mov eax, [ebp + 8];
    mov eax, [ebp + 12];
    mov esi, [eax + 4];
    xor ebx, ebx;
    mov ecx, 8;

count_loop: movzx edx, byte [esi];
    and edx, 1;
    add ebx, edx;
    inc esi;
    loop count_loop;
    test ebx, 1;
    jz even_parity;

odd_parity: mov dword [esp], 0;
    jmp print_parity;

even_parity: mov dword [esp], 1;

print_parity: push output_msg;
    call _printf;
    add esp, 8;
    mov esp, ebp;
    pop ebp;
    ret;