#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   
#include <pthread.h>

#define NUM_THREADS 5

void *hello (void *arg) { /* thread main */
        int rr=rand()%10+1;
	printf("The random value is  %d\n",rr);
	return rr;
}

int main (void) {
        time_t t1;
        srand ( (unsigned) time (&t1));
	int i , sum=0;
	pthread_t tid[NUM_THREADS];
	int return_value[NUM_THREADS];
	
	for (i = 0; i < NUM_THREADS; i++) { /* create/fork threads */
		pthread_create(&tid[i], NULL, hello, NULL);
	}
	
	for (i = 0; i < NUM_THREADS; i++) { /* wait/join threads */
		pthread_join(tid[i], (void*)&return_value[i]);
		 sum+=return_value[i];
	}
	printf( "The sum of random values is = %i\n", sum );  
	return 0;
}
