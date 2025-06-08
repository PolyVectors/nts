#include "../std/types.h"

#define TERMIOS_ECHO (1 << 3)
#define TERMIOS_ICANON (1 << 8)

struct termios {
  u32 iflag;
  u32 oflag;
  u32 cflag;
  u8 cc[20];
};
