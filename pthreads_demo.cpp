//pthreads_demo.cpp

/*
  A very simple example demonstrating the usage of pthreads.
  Compile: g++ -o pthreads_demo pthreads_demo.cpp -lpthread
  Execute: ./pthreads_demo
*/

#include <pthread.h>
#include <stdio.h>

using namespace std;

//The thread
void * thread_func1 (void *data)
{
  char *tname = (char *) data;

  printf("Lets go %s!\n", tname);

  pthread_exit (0);
}

void * thread_func2 (void *data)
{
  char *tname = (char *) data;

  printf("I love the %s!\n", tname);

  pthread_exit (0);
}

void * thread_func3 (void *data)
{
  char *tname = (char *) data;

  printf("%s will the championship!\n", tname);

  pthread_exit (0);
}


int main ()
{
  pthread_t id1, id2, id3;           //thread identifiers
  pthread_attr_t attr1, attr2, attr3;  //set of thread attributes
  char *tnames[3] = { (char *)"Lakers", (char *)"Dodgers", (char *)"Rams" }; //names of threads
  //get the default attributeså
  pthread_attr_init (&attr1);
  pthread_attr_init (&attr2);
  pthread_attr_init (&attr3);

  //create the threads 
  pthread_create (&id1, &attr1, thread_func1, tnames[0]);//thread 1
  pthread_create (&id2, &attr2, thread_func2, tnames[1]);//thread 2
  pthread_create (&id3, &attr3, thread_func3, tnames[2]);//thread 3

  //wait for the threads to exit
  pthread_join (id1, NULL);
  pthread_join (id2, NULL);
  pthread_join (id3, NULL);

  return 0;
}
