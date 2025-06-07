format ELF64

public std_mem_malloc
public std_mem_free

section '.text' executable
std_mem_malloc:
        mov rax, 9
        mov rsi, rdi
        mov rdx, PROT_READ
        or rdx, PROT_WRITE
        mov r10, MAP_PRIVATE
        or r10, MAP_ANONYMOUS
        mov r8, -1
        xor r9, r9

        syscall
        ret

std_mem_free:
        mov rax, 11

        syscall
        ret

section '.data' writable
PROT_READ = 1
PROT_WRITE = 2

MAP_PRIVATE = 2
MAP_ANONYMOUS = 0x20
