#include "../std/std.h"
#include "../termios/termios.h"

void enableRawMode() {
  struct termios raw;

  termios_getattr(STDIN_FILENO, &raw);

  /* TODO (https://github.com/EastonA01/text-editor-in-c/blob/master/kilo.c#L146-L151):
  
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
  */

  termios_setattr(STDIN_FILENO, TERMIOS_SETSF, &raw);
}

void _start() {
  enableRawMode();

  char c;
  while (std_io_read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  
  std_sys_exit(0);
}
