#include "../std/std.h"

void _start() {
  // TODO: strcpy, dynamic arrays
  char* array = (char *)std_mem_malloc(sizeof(char) * 4);

  array[0] = 'H';
  array[1] = 'i';
  array[2] = 0xA;
  array[3] = 0;

  std_io_print(array, STDOUT_FILENO);

  std_mem_free((uint64_t)array, sizeof(char) * 4);
  std_sys_exit(0);
}
