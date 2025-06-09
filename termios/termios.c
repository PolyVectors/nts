#include "../std/std.h"
#include "termios.h"

i32 termios_getattr(i32 fd, struct termios* termios_p) {
  struct termios ioctlTermios;
  i32 errorValue = std_sys_ioctl(fd, TERMIOS_GETS, (u64)&ioctlTermios);

  if (errorValue == 0) {
    termios_p->c_iflag = ioctlTermios.c_iflag;
    termios_p->c_oflag = ioctlTermios.c_oflag;
    termios_p->c_iflag = ioctlTermios.c_cflag;
    termios_p->c_lflag = ioctlTermios.c_lflag;

    termios_p->c_line = ioctlTermios.c_line;
    std_mem_cpy(termios_p->c_cc, ioctlTermios.c_cc, __TERMIOS_KERNEL_NCCS * sizeof(u8));
  }

  return errorValue;
}

i32 termios_setattr(i32 fd, u64 cmd, struct termios *termios_p) {
  struct termios* ioctlTermios = std_mem_alloc(sizeof(struct termios));
  
  ioctlTermios->c_iflag = termios_p->c_iflag & ~020000000000;
  ioctlTermios->c_oflag = termios_p->c_oflag;
  ioctlTermios->c_cflag = termios_p->c_cflag;
  ioctlTermios->c_lflag = termios_p->c_lflag;

  ioctlTermios->c_line = termios_p->c_line;
  for (u8 i = 0; i < __TERMIOS_KERNEL_NCCS; i++)
    ioctlTermios->c_cc[i] = termios_p->c_cc[i];

  i32 errorValue = std_sys_ioctl(fd, cmd, (u64)ioctlTermios);
  std_mem_free(ioctlTermios, sizeof(struct termios));

  return errorValue;
}
