global clock_counter

section .text
clock_counter:
    xor rax, rax
    rdtsc
    shl rdx, 32
    or rax, rdx
    ret