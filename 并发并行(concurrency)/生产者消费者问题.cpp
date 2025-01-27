#include<stdio.h>
#include<pthread.h>
pthread_mutex_t the_mutex;
pthread_condt condc,condp;
int buffer=0;

void *producer(*ptr){
	for(int i =0;i<MAX;i++){
		pthread_mutex_lock(&the_mutex);
		while(buffer!=0) pthread_cond_wait(&condp,&the_mutex);
		buffer = i;
		pthread_cond_signal(&condc);/*这个条件变量与上面的条件变量不相同*/
		pthread_mutex_unlock(&the_mutex);
	}
	pthread_exit(0);
}

void *consumer(*ptr){
	for(int i =0;i<MAX;i++){
		pthread_mutex_lock(&the_mutex);
		while(buffer==0) pthread_cond_wait(&condc,&the_mutex);
		buffer = 0;
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&the_mutex);
	}
	pthread_exit(0);
}

int main(){
	pthread_t pro,con;
	pthread_mutex_init(&the_mutex,0);
	pthread_cond_init(&condc,0);
	pthread_cond_init(&condp,0);
	pthread_create(&con,0,consumer,0);
	pthread_create(&pro,0,producer,0);
	pthread_join(pro,0);
	pthread_join(con,0);
	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&the_mutex);
}