format ELF64

public std_mem_malloc
public std_mem_free
public std_mem_copy

section '.text' executable
std_mem_malloc:
        mov rax, 9
        lea rsi, [rdi]
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

std_mem_copy:
        xor r15, r15
.copy_byte:
        mov r14b, [rsi + r15]
        cmp r14b, 0
        je .after_copy_byte
        
        mov BYTE [rdi + r15], r14b
        inc r15
        jmp .copy_byte
.after_copy_byte:
        ret

section '.data' writable
PROT_READ = 1
PROT_WRITE = 2

MAP_PRIVATE = 2
MAP_ANONYMOUS = 0x20
