#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>


void HandleSignal(int a){
    if(a == SIGINT)
    printf("%s\n","signal SIGINT" );
}
void SigKill(int a){
    if(a == SIGKILL)
    printf("%s\n","signal SIGKILL" );
}
void SigStop(int a){
    if(a == SIGSTOP)
    printf("%s\n","signal SIGSTOP" );
}
void SigUsr1(int a){
    if(a == SIGUSR1)
    printf("%s\n","signal SIGUSR!" );
}

int main()
{
    signal(SIGINT,HandleSignal);
    signal(SIGKILL,SigKill);
    signal(SIGSTOP,SigStop);
    signal(SIGUSR1,SigUsr1);
int a = 10;
    while(a == 10){
        printf("%s\n","signal waiting");
        sleep(1);
    }

}
