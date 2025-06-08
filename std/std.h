#include "types.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

extern void std_io_print(char* buf, i32 fd);
extern int std_io_read(i32 fd, char* buf, u64 count);

extern void* std_mem_malloc(u64 lengthint);
extern void std_mem_free(void* addr, u64 lengthint);
extern void std_mem_copy(void* dest, void* src);

extern void std_sys_exit(int error_code);
