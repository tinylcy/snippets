/**
 * Demonstrate how to share a region of mapped memory between a parent and 
 * child process without having to create a mapped file, either through the creation
 * of an anonymous memory mapping or through the mapping of /dev/zero.
 */

#ifdef USE_MAP_ANON
#define _BSD_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int *addr;

#ifdef USE_MAP_ANON
    addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
				MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if(addr == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

#else
    int fd;
    fd = open("/dev/zero", O_RDWR);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED) {
        perror("mmap");
        return -1;
    }
    
    if(close(fd) == -1) {
        perror("close");
        return -1;    
    }
#endif

    *addr = 1;
    
    switch(fork()) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            printf("Child started, value = %d\n", *addr);
            (*addr)++;
            if(munmap(addr, sizeof(int)) == -1) {
                perror("munmap");
                return -1;
            }
            return 0;
        default:
            if(wait(NULL) == -1) {
                perror("wait");
                return -1;
            }
            printf("In parent, value = %d\n", *addr);
            if(munmap(addr, sizeof(int)) == -1) {
                perror("munmap");
                return -1;
            }
    }

    return 0;
}
