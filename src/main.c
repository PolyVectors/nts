#include "../std/std.h"

void _start() {
  // TODO: dynamic arrays
  char* array = (char *)std_mem_malloc(sizeof(char) * 20);
  std_mem_copy(array, "Hello, world!\n");

  std_io_print(array, STDOUT_FILENO);

  std_mem_free(array, sizeof(char) * 4);
  std_sys_exit(0);
}
