#include "include/syscall.h"

int main(void)
{
    SYSCALL(__NR_write, 1, "Hello World", 11); // Print Hello World using write syscall
    SYSCALL(__NR_exit, 10); // Exit the program and returning 10 using exit syscall
    return 0;
}
