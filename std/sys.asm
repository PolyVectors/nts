format ELF64

public std_sys_exit
public std_sys_syscall3

section '.text' executable
std_sys_exit:
        mov rax, 60
        syscall
        ret

std_sys_syscall3:
        mov rax, rdi
        mov rdi, rsi
        mov rsi, rdx
        mov rdx, rcx
        
        syscall
        ret
