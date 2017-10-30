/**
 * Use mmap() plus write() to display the contents of a file on standard output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *addr;
    int fd;
    struct stat st;

    if(argc != 2) {
        fprintf(stderr, "%s filename\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    if(fstat(fd, &st) == -1) {
        perror("fstat");
        return -1;
    }

    if(st.st_size == 0) {
        perror("file length equals zero.");
        return 0;
    }

    addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(addr == MAP_FAILED) {
        perror("map");
        return -1;
    }

    if(write(STDOUT_FILENO, addr, st.st_size) != st.st_size) {
        perror("write");
        return -1;
    }

    if(close(fd) == -1) {
        perror("close");
        return -1;
    }


    if(munmap(addr, st.st_size) == -1) {
        perror("munmap");
        return -1;
    }

    return 0;
}
