format ELF64

public termios_kernel_ioctl
section '.text' executable

termios_kernel_ioctl:
        mov rax, 16
        syscall
        ret
