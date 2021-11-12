/*  Chad Callender
    CMPS 4103
    Mini Project #2
*/
// To compile use gcc mini_project_2.1.c

#include<stdio.h>
#include<pthread.h>     //POSIX thread library 
#include<stdlib.h>

int TOTAL = 0;          //global variable to hold result of sum
pthread_mutex_t mutex;  //declaration of mutex to control access to critical region
int array[6000];        //array of values to be added

struct args
{   //parameters to be passed into add_num function
    int tid;        //thread id
    int array[6000];
}args;

void *add_num(void *nums);

int main()
{
    struct args *v = malloc(sizeof(args));          //malloc allows space to be allocated for struct
    v->tid = 0;
    pthread_t thread[3];                            //declares threads to be used
    pthread_mutex_init(&mutex, 0);                  //initializes mutex to default value

    for(int i  = 0; i < 6000; i++)
        array[i] = i+1;                             //populating the array

    for(int i = 0; i < 3; i++)
    {
        pthread_mutex_lock(&mutex);                 //locks mutex to enter critical region
        pthread_create(&thread[i], NULL, add_num, (void *)v);      //thread does its stuff
    }

    pthread_join(thread[0], NULL);                                  //synchronizes the threads
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);

    printf("Total sum is %d (with semaphores)", TOTAL);

    exit(0);
}

void *add_num(void *nums)
{   // takes a struct nums as a parameter and sums a range of consecutive
    // numbers from start to stop.

    ((struct args*)nums) -> tid += 1;           //increments tid to get the ith partition of array values
    int tid = ((struct args*)nums) -> tid;

    //pthread_mutex_unlock(&mutex);               //unlocks mutex to exit critical region

    printf("tid: %d\n", tid);

    int start = (tid - 1) * 2000;               //range of values to be added
    int stop = tid * 2000 - 1;

    for(int i = start; i <= stop; i++)
    {
        //pthread_mutex_lock(&mutex);
        TOTAL += array[i];

    }
    
    pthread_mutex_unlock(&mutex);               //unlocks mutex to exit critical region
}