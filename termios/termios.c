#include "../termios/termios.h"
#include "../std/types.h"

i32 termios_tcgetattr(i32 fd, struct termios* termios_p) {
  if (termios_ioctl(fd, TERMIOS_IOCTL_TCGETS, termios_p))
    return -1;
  return 0;
}

i32 termios_tcsetattr(i32 fd, i32 act, const struct termios *termios_p) {
  return termios_ioctl(fd, TERMIOS_IOCTL_TCSETS + act, termios_p);
}
