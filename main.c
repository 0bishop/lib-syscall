#include "include/syscall.h"

int main(void)
{
    SYSCALL(1, 1, "Hello World", 11); // Print Hello World using write syscall
    SYSCALL(60, 10); // Exit the program and returning 10 using exit syscall
    return 0;
}
