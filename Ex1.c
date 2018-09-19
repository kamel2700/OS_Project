#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int N = 1;

void *thread_funk(){
	printf("%s%i%s\n","thread ", N++, " to" );
}

int main(){
	printf("%s", "parallel\n");
	pthread_t ThreadID;
	for (int i = 0; i <= 3; i++){
		printf("%s%i%s", "Thread " ,i , " creates\n" );
		pthread_create(&ThreadID, NULL, thread_funk, NULL);}
	sleep(2);
	printf("%s", "\nsequential:\n");

	for (int j = 0; j <= 3; j++){
		printf("%s%i%s", "thread " ,N , " creates\n" );
		pthread_create(&ThreadID, NULL, thread_funk, NULL);
		pthread_join(ThreadID, NULL);
	}
	pthread_exit(NULL);
	return 0;
}
