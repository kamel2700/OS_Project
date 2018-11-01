#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("ex1.txt", O_RDWR);

    char *str = "This is a nice day\n";
    int size = strlen(str);
    ftruncate(fd, size);

    char *file_addr = mmap(NULL, strlen(str), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    strcpy(file_addr, str);
    munmap(file_addr, size);

    close(fd);
    return 0;
}