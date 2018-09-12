#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
int pid = fork();
int n = 0;
if (pid > 0) {
printf("Hello from parent [%d - %d]\n", pid, n);
} else if (pid == 0) {
printf("Hello from child [%d - %d]\n", pid, n);
} else {
return 0;
}
return 1;
}
