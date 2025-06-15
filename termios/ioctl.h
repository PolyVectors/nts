#include "../std/types.h"

#define TERMIOS_IOCTL_TCGETS 0x5401
#define TERMIOS_IOCTL_TCSETS 0x5402

#define TERMIOS_TCSAFLUSH 2

i32 termios_ioctl(i32 fd, i32 req, ...);
extern i32 termios_kernel_ioctl(u32 fd, u32 cmd, u64 arg);
