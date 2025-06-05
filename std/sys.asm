format ELF64

public std_sys_exit

std_sys_exit:
        mov rax, 60
        syscall
        ret
