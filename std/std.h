#include "types.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

extern void std_io_print(i32 fd, const u8* buf);
extern i32 std_io_read(i32 fd, char* buf, u64 count);

extern void* std_mem_alloc(u64 lengthint);
extern void std_mem_free(void* addr, u64 lengthint);
extern void std_mem_strcpy(void* dest, const void* src);
extern void std_mem_cpy(void* dest, const void* src, u32 count);

extern void std_sys_exit(i32 error_code);
extern i32 std_sys_ioctl(u64 fd, u64 cmd, u64 rdx);
