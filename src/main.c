#include "../std/std.h"
#include "../termios/termios.h"

void enableRawMode() {
  struct termios raw;
  termios_tcgetattr(STDIN_FILENO, &raw);

  raw.c_lflag &= ~(TERMIOS_ECHO | TERMIOS_ICANON);
  termios_tcsetattr(STDIN_FILENO, 2, &raw);
}

void _start() {
  enableRawMode();

  char c;
  while (std_io_read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  
  std_sys_exit(0);
}
