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
    write(p[1],line1,LARGE);
    read(p[0], line2,LARGE);
    printf("%s\n", line2);

    return 0;

}
