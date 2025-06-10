format ELF64

public std_sys_exit

section '.text' executable
std_sys_exit:
        mov rax, 60
        syscall
        ret
