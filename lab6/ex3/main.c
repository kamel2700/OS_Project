#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>


void HandleSignal(int a){
    printf("%s\n","end of signal" );
}

int main()
{
    signal(SIGINT,HandleSignal);
int a = 10;
    while(a == 10){
        printf("%s\n","signal waiting");
        sleep(1);
    }

}
