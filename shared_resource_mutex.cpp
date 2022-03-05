//shared_resource_mutex.cpp

/*
Compile: g++ -o shared_resource_mutex shared_resource_mutex.cpp -lpthread
Execute: ./shared_resource_mutex
Try to execute: $time./shared_resource_mutex
*/

#include <stdio.h>
#include <pthread.h>

#define iterations 300000000
long long shared_resource = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// Thread function to modify shared resource
void* inc_dec_resource(void* arg){
    //get the pointer from main thread and dereference it to put the value in resource_value
    int resource_value = *(int *) arg;
    for(int i=0; i < iterations; i++){
        pthread_mutex_lock(&mutex);//added the lock
        shared_resource += resource_value;
        pthread_mutex_unlock(&mutex);//added unlock... doing so gives an output of 0
    }
    pthread_exit(NULL);
}

int main(void){

    // Thread 1 to increment shared resource
    pthread_t tid1, tid2;
    int value1 = 1;
    pthread_create(&tid1, NULL, inc_dec_resource, &value1);
    // Thread 2 to increment shared resource
    int value2 = -1;
    pthread_create(&tid2, NULL, inc_dec_resource, &value2);
    pthread_join(tid2, NULL); //switched tid1 and tid2
    pthread_join(tid1, NULL); //no difference on output before adding lock and unlock
    printf("Shared resource value: %lld\n", shared_resource);

    return 0;
}
