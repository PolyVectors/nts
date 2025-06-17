#include "../std/std.h"
#include "../termios/termios.h"

struct termios termios_default;

void enableRawMode() {
  termios_tcgetattr(STDIN_FILENO, &termios_default);

  struct termios* raw = std_mem_alloc(sizeof(struct termios));
  std_mem_cpy(raw, &termios_default, sizeof(struct termios));

  raw->c_lflag &= ~(TERMIOS_ECHO | TERMIOS_ICANON);
  termios_tcsetattr(STDIN_FILENO, TERMIOS_TCSAFLUSH, raw);

  std_mem_free(raw, sizeof(struct termios));
}

void disableRawMode() {
  termios_tcsetattr(STDIN_FILENO, TERMIOS_TCSAFLUSH, &termios_default);
}

void _start() {
  enableRawMode();
  std_io_print(STDOUT_FILENO, "YYYY-MM-DD\n  • ");

  char c;

  while (std_io_read(STDIN_FILENO, &c, 1) == 1 && c != 27) {
    if (c != '\n')
      std_io_print(STDOUT_FILENO, &c);
    else
      std_io_print(STDOUT_FILENO, "\n  • ");
  }

  std_io_print(STDOUT_FILENO, "\n");

  disableRawMode();
  std_sys_exit(0);
}
