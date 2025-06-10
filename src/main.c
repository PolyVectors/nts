#include "../std/std.h"

void enableRawMode() {

}

void _start() {
  enableRawMode();

  char c;
  while (std_io_read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  
  std_sys_exit(0);
}
