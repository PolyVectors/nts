// adapted from glibc

#include "../std/types.h"

#define TERMIOS_ECHO (1 << 3)
#define TERMIOS_ICANON (1 << 8)

// this is actually __kernel_termios, no abstractions

struct termios {
  u32 iflag;
  u32 oflag;
  u32 cflag;
  u32 lflag;
  
  u8 cchars[19];
  u8 line;
  
  i32 ispeed;
  i32 ospeed;
};

i32 termios_getattr(i32 fd, struct termios *termios_p);
i32 termios_setattr(i32 fd, i32 optional_actions, const struct termios *termios_p);
