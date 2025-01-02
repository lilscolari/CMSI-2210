section .data
    values dd 0x01345678, 0x00654321, 0x01BBCCDD, 0x01223344, 0x00ADBEEF;
    msg db "Original: 0x%08X, Swapped: 0x%08X", 10, 0;

section .bss
    result resd 1;

section .text
    extern _printf;
    extern _nbocConverter;
    global _main;

_main: lea esi, [values];
    mov ecx, 5;

.next_value: mov eax, [esi];
    push eax;
    call _nbocConverter;
    add esp, 4;
    mov [result], eax;
    push dword [result];
    push dword [esi];
    push msg;
    call _printf;
    add esp, 12;
    add esi, 4;
    dec ecx;
    loop .next_value;
    ret;