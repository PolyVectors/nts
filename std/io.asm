format ELF64

public std_io_print

std_io_print:
        push rdi
        push rdi
        
        xor al, al
        repne scasb

        mov rdx, rdi
        pop rdi
        sub rdx, rdi

        mov rax, 1
        mov rdi, 1
        pop rsi
        
        syscall
        ret
