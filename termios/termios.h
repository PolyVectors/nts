// adapted from glibc

#include "../std/types.h"

#define TERMIOS_ECHO (1 << 3)
#define TERMIOS_ICANON (1 << 8)

// this is actually __kernel_termios, no abstractions

struct termios {
  u32 c_iflag;
  u32 c_oflag;
  u32 c_cflag;
  u32 c_lflag;
  
  u8 c_cc[19];
  u8 c_line;
  
  i32 c_ispeed;
  i32 c_ospeed;
};

i32 termios_getattr(i32 fd, struct termios* termios_p);
i32 termios_setattr(i32 fd, i32 optional_actions, const struct termios *termios_p);
