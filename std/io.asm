format ELF64

public std_io_print

section '.text' executable
std_io_print:
        push rsi
        push rdi
        push rdi
        
        xor al, al
        repne scasb

        mov rdx, rdi
        pop rdi
        sub rdx, rdi
        dec rdx

        mov rax, 1
        pop rsi
        pop rdi
        
        syscall
        ret

