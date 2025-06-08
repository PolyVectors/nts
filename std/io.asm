format ELF64

public std_io_print
public std_io_read

section '.text' executable
std_io_print:
        push rsi
        push rdi
        push rdi
        
        xor al, al
        repne scasb

        lea rdx, [rdi]
        pop rdi
        sub rdx, rdi
        dec rdx

        mov rax, 1
        pop rsi
        pop rdi
        
        syscall
        ret

std_io_read:
        mov rax, 0
        syscall
        ret
