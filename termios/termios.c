#include "../std/std.h"
#include "termios.h"

i32 termios_getattr(i32 fd, struct termios *termios_p) {
  struct termios k_termios;

  // https://linux.die.net/man/2/ioctl_list
  i32 retval = std_sys_syscall3(16, fd, 0x00005401, (u64)&k_termios);

  if (retval == 0)
    std_io_print(STDOUT_FILENO, "we're in\n");

  return retval;
}

i32 termios_setattr(i32 fd, i32 optional_actions, const struct termios *termios_p) {
  return 0;
}
