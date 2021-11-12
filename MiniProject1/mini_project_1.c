/*  Chad Callender
    CMPS 4103
    Mini Project #1
*/
// To compile use gcc mini_project_1.c -lpthread

#include<stdio.h>
#include<pthread.h>     //POSIX thread library 
#include<stdlib.h>

struct args
{   //parameters to be passed into print_num function
    int num_1;
    int num_2;
};

struct args *v1, *v2, *v3;

void *print_num(void *nums);

int main()
{
    int num = 0;
          //vn holds start-stop values for the nth partition of numbers
    pthread_t thread1, thread2;         //declares threads to be used

    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("You entered %d\n", num);

    v1->num_1 = 1;                      //first partition values
    v1->num_2 = num/3;
    v2->num_1 = (num/3) + 1;            //second partition values
    v2->num_2 = (2*num)/3;

    printf("v1: %d\n", v1);
    printf("v2: %d\n", v2);

    pthread_create(&thread1, NULL, print_num, (void *)v1);      //first thread
    pthread_create(&thread2, NULL, print_num, (void *)v2);      //second thread

    for (int i = ((2*num)/3) + 1; i <= num; ++i)
        //prints the third partition of numbers
        printf("%d ", i);

    exit(0);
}

void *print_num(void *nums)
{   // takes a struct nums as a parameter and prints a range of consecutive
    // numbers from start to stop.
    int start = ((struct args*)nums) -> num_1;
    int stop = ((struct args*)nums) -> num_2;
    for(int i = start; i <= stop; i++)
        printf("%d ", i);
}