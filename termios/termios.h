#include "../termios/ioctl.h"
#include "../std/types.h"

typedef u8 cc_t;
typedef u32 speed_t;
typedef u32 tcflag_t;

#define NCCS 32

#define TERMIOS_ECHO   0000010
#define TERMIOS_ICANON 0000002

struct termios {
  tcflag_t c_iflag;
  tcflag_t c_oflag;
  tcflag_t c_cflag;
  tcflag_t c_lflag;

  cc_t c_line;
  cc_t c_cc[NCCS];
};


i32 termios_tcgetattr(i32 fd, struct termios* termios_p);
i32 termios_tcsetattr(i32 fd, i32 act, const struct termios *termios_p);
