#ifndef _UNISTD_H
#define _UNISTD_H

#include <syscall.h>
#include <types.h>

#define _syscall0(ret_t, fn) \
ret_t fn() \
{ \
    ret_t ret;  \
    asm volatile ( "int $0x80 \n" \
            :"=a"(ret) \
            :"a"(SYS_##fn) \
            :"cc", "memory"); \
    return ret; \
}

#define _syscall1(ret_t, fn, t1, arg1) \
ret_t fn(t1 arg1) \
{ \
    ret_t ret;  \
    asm volatile ( "int $0x80 \n" \
            :"=a"(ret) \
            :"a"(SYS_##fn), "b"(arg1) \
            :"cc", "memory"); \
    return ret; \
}

#define _syscall2(ret_t, fn, t1, arg1, t2, arg2) \
ret_t fn(t1 arg1, t2 arg2) \
{ \
    ret_t ret;  \
    asm volatile ( "int $0x80 \n" \
            :"=a"(ret) \
            :"a"(SYS_##fn), "b"(arg1), "c"(arg2) \
            :"cc", "memory"); \
    return ret; \
}

#define _syscall3(ret_t, fn, t1, arg1, t2, arg2, t3, arg3) \
ret_t fn(t1 arg1, t2 arg2, t3 arg3) \
{ \
    ret_t ret;  \
    asm volatile ( "int $0x80 \n" \
            :"=a"(ret) \
            :"a"(SYS_##fn), "b"(arg1), "c"(arg2), "d"(arg3) \
            :"cc", "memory"); \
    return ret; \
}

#define _syscall4(ret_t, fn, t1, arg1, t2, arg2, t3, arg3, t4, arg4) \
ret_t fn(t1 arg1, t2 arg2, t3 arg3, t4 arg4) \
{ \
    ret_t ret;  \
    asm volatile ( "int $0x80 \n" \
            :"=a"(ret) \
            :"a"(SYS_##fn), "b"(arg1), "c"(arg2), "d"(arg3), "S"(arg4) \
            :"cc", "memory"); \
    return ret; \
}

#ifdef __cplusplus
extern "C" {
#endif

int write(int fildes, const void *buf, size_t nbyte);
int close(int fd);
int read(int fildes, void *buf, size_t nbyte);
int fork();
int exec(const char *path, char *const argv[], char *const envp[]);
int execve(const char *path, char *const argv[], char *const envp[]);
int getpid();
int sleep(int);
int exit();
int readdir(unsigned int fd, struct dirent *dirp, unsigned int count);

// return -1 if no child, or pid of any of children exited
int wait();

#ifdef __cplusplus
}
#endif
#endif
