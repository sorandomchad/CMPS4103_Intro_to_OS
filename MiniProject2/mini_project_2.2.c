/*  Chad Callender
    CMPS 4103
    Mini Project #2
*/
// To compile use gcc mini_project_1.c -lpthread

#include<stdio.h>
#include<pthread.h>     //POSIX thread library 
#include<stdlib.h>

int TOTAL = 0;          //global variable to hold result of sum
pthread_mutex_t mutex;  //declaration of mutex to control access to critical region
int array[6000];        //array of values to be added
// int *tid;
int *tid;


// struct args
// {   //parameters to be passed into add_num function
//     int tid;        //thread id
//     array;
// }args;

void *add_num(void *thread_id);

int main()
{
    
    printf("tida: %d\n", tid);
    tid = 0;
    // struct args *v = malloc(sizeof(args));          //malloc allows space to be allocated for struct
    pthread_t thread[3];                            //declares threads to be used
    pthread_mutex_init(&mutex, 0);                  //initializes mutex to default value

    for(int i  = 0; i < 6000; i++)
        array[i] = i+1;                             //populating the array

    for(int i = 0; i < 3; i++)
    {
        printf("i: %d\n", i);
        pthread_mutex_lock(&mutex);                 //locks mutex to enter critical region
        pthread_create(&thread[i], NULL, add_num, (void *)tid);      //thread does its stuff
    }

    pthread_join(thread[0], NULL);                                  //synchronizes the threads
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);

    printf("Total sum is %d", TOTAL);

    exit(0);
}

void *add_num(void *tid)
{   // takes a struct nums as a parameter and sums a range of consecutive
    // numbers from start to stop.
              //increments tid to get the ith partition of array values
    printf("thread: %d\n", tid);
    int *tid_1;
    tid_1 = ((int *)tid) + 1;
    printf("tid: %d\n", tid_1);
    pthread_mutex_unlock(&mutex);               //unlocks mutex to exit critical region


    int start = (*tid_1 - 1) * 2000;               //range of values to be added
    int stop = *tid_1 * 2000 - 1;
    printf("start: %d, stop: %d\n", start, stop);

    for(int i = start; i <= stop; i++)
        TOTAL += array[i];
}