#ifndef SYSCALL_H_
    #define SYSCALL_H_
    #define NULL ((void *)0)
    #define SYSCALL syscall

    #include <stdarg.h>

    typedef unsigned long int uint64_t;
    static inline uint64_t syscall(uint64_t syscall_number, ...);

    static inline uint64_t syscall(uint64_t syscall_number, ...)
    {
        __gnuc_va_list args;
        __builtin_va_start(args, syscall_number);

        uint64_t ret;
        asm volatile("mov %1, %%rax\n"
                    "mov %2, %%rdi\n"
                    "mov %3, %%rsi\n"
                    "mov %4, %%rdx\n"
                    "mov %5, %%r10\n"
                    "mov %6, %%r8\n"
                    "mov %7, %%r9\n"
                    "syscall\n"
                    "mov %%rax, %0\n"
                    : "=r"(ret)
                    : "r"(syscall_number),
                    "r"(__builtin_va_arg(args, uint64_t)),
                    "r"(__builtin_va_arg(args, uint64_t)),
                    "r"(__builtin_va_arg(args, uint64_t)),
                    "r"(__builtin_va_arg(args, uint64_t)),
                    "r"(__builtin_va_arg(args, uint64_t)),
                    "r"(__builtin_va_arg(args, uint64_t))
                    : "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9");

        __builtin_va_end(args);

        return ret;
    }

#endif
