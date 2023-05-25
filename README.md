# kern_syscall

## Recoding syscall's used in LibC at the deepest level
```usage:```

```c
#include "include/syscall.h"

int main(void)
{
    SYSCALL(__NR_write, 1, "Hello World", 11); // Print Hello World using write syscall
    SYSCALL(__NR_exit, 10); // Exit the program and returning 10 using exit syscall
    return 0;
}

```

**You can use preprocessor directive like __NR_write for the rax syscall number or just the correponding number (1 for write)**
**see,** *https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/*