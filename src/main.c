#include "../std/std.h"
#include "../termios/termios.h"

void enableRawMode() {
  struct termios raw;
  termios_getattr(STDIN_FILENO, &raw);
}

void _start() {
  enableRawMode();
  std_sys_exit(0);
}
