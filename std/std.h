typedef unsigned long int uint64_t;

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

extern void std_io_print(char* buf, uint64_t fd);

extern void* std_mem_malloc(uint64_t lengthint);
extern void std_mem_free(void* addr, uint64_t lengthint);
extern void std_mem_copy(void* dest, void* src);

extern void std_sys_exit(int error_code);
