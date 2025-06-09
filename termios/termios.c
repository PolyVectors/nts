#include "../std/std.h"
#include "termios.h"

i32 termios_getattr(i32 fd, struct termios* termios_p) {
  struct termios copy_termios;
  // https://linux.die.net/man/2/ioctl_list
  int ret_value = std_sys_syscall3(16, fd, 0x00005401, (u64)&copy_termios);

  if (ret_value == 0) {
    termios_p->c_iflag = copy_termios.c_iflag;
    termios_p->c_oflag = copy_termios.c_oflag;
    termios_p->c_iflag = copy_termios.c_cflag;
    termios_p->c_lflag = copy_termios.c_lflag;


    std_mem_copy(termios_p->c_cc, copy_termios.c_cc);
    termios_p->c_line = copy_termios.c_line;

    termios_p->c_ispeed = copy_termios.c_ispeed;
    termios_p->c_ospeed = copy_termios.c_ospeed;
  } 

  return ret_value;
}

i32 termios_setattr(i32 fd, i32 optional_actions, const struct termios *termios_p) {
  return 0;
}
