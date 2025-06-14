#include <stdarg.h>

#include "../termios/ioctl.h"
#include "../std/types.h"

i32 termios_ioctl(i32 fd, i32 req, ...) {
  void* arg;
  va_list args;
  __builtin_va_start(args, req);
  arg = __builtin_va_arg(args, void*);
  __builtin_va_end(arg);
  return termios_kernel_ioctl(fd, req, (u64)arg);
}
