format ELF64

public std_sys_exit
public std_sys_ioctl

section '.text' executable
std_sys_exit:
        mov rax, 60
        syscall
        ret

std_sys_ioctl:
        mov rax, 16
        syscall
        ret
