extern void std_io_print(char* buf);
extern void std_sys_exit(int error_code);

void _start() {
  std_io_print("Hello, world!\n");
  std_sys_exit(0);
}
