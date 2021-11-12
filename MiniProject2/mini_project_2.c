/*  Chad Callender
    CMPS 4103
    Mini Project #2
*/
// To compile use gcc mini_project_1.c -lpthread

#include<stdio.h>
#include<pthread.h>     //POSIX thread library 
#include<stdlib.h>

int TOTAL = 0;          //global variable to hold result of sum
pthread_mutex_t the_mutex; 

struct args
{   //parameters to be passed into print_num function
    int tid;
    int values[6000];
}args;

void *add_num(void *nums);

int main()
{
    int num = 0;
    struct args *v = malloc(sizeof(args));          //vn holds start-stop values for the nth partition of numbers
    pthread_t thread[3];        //declares threads to be used
    pthread_mutex_init(&the_mutex, 0);
    int array[6000];

    for(int i  = 0; i < 6000; i++)
        array[i] = i+1;

    v->tid = 0;
    for(int i = 0; i < 3; i++)
    {
        // v->tid = i+1;
        // printf("tid: %d\n", v->tid);
        for(int j = 0; j < 6000; j++)
            v->values[j] = array[j];
        pthread_mutex_lock(&the_mutex);
        pthread_create(&thread[i], NULL, add_num, (void *)v);      //first thread
    }

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);

    printf("Total sum is %d", TOTAL);

    exit(0);
}

void *add_num(void *nums)
{   // takes a struct nums as a parameter and prints a range of consecutive
    // numbers from start to stop.

    ((struct args*)nums) -> tid += 1;
    int tid = ((struct args*)nums) -> tid;
    pthread_mutex_unlock(&the_mutex);

    printf("tid: %d\n", tid);
    int array[6000];
    for (int i = 0; i < 6000; i++)
        array[i] = ((struct args*)nums) -> values[i];

    int start = (tid - 1) * 2000;
    int stop = tid * 2000 - 1;

    for(int i = start; i <= stop; i++)
        TOTAL += array[i];
}