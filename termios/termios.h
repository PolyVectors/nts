// adapted from glibc

#include "../std/types.h"

#define TERMIOS_ECHO (1 << 3)
#define TERMIOS_ICANON (1 << 8)

#define TERMIOS_GETS 0x00005401
#define TERMIOS_SETSF 0x00005404

#define __TERMIOS_KERNEL_NCCS 19

// this is actually __kernel_termios, no abstractions

struct termios {
  u32 c_iflag;
  u32 c_oflag;
  u32 c_cflag;
  u32 c_lflag;
  
  u8 c_cc[__TERMIOS_KERNEL_NCCS];
  u8 c_line;
};

i32 termios_getattr(i32 fd, struct termios* termios_p);
i32 termios_setattr(i32 fd, u64 cmd, struct termios *termios_p);
