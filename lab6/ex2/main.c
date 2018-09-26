#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#define LARGE 6
char* line1 = "qwerty";
char* line2[LARGE];


int main()
{
    int p[2];
    if(pipe(p) < 0)
        exit(1);
    if(fork() == 0) {
        read(p[0], line2,LARGE);
        printf("%s\n", line2);
    }else
        write(p[1],line1,LARGE);



    return 0;

}
