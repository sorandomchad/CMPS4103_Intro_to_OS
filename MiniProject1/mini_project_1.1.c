/*  Chad Callender
    CMPS 4103
    Mini Project #1
*/
// To compile use gcc mini_project_1.1.c

#include<stdio.h>
#include<unistd.h>     //POSIX fork library 
#include<stdlib.h>

void print_num(int num_1, int num_2);

int main()
{
    int num = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("You entered %d\n", num);

    pid_t child_1, child_2;
    child_1 = fork();                       // creates first child process
    // fork() returns a pid of 0 to the child process and a pid > 0 to the parent

    if(child_1 == 0)
        // child process
        print_num(1, num/3);
    else
    {   // parent process
        child_2 = fork();                   // creates second child
        if (child_2 == 0)
            // child process
            print_num((num/3) + 1, (2*num)/3);
        else
            // parent process
            print_num(((2*num)/3) + 1, num);
    }

    return 0;
}

void print_num(int num_1, int num_2)
{   // takes two numbers as parameters and prints a range of consecutive
    // numbers from start to stop.
    int start = num_1;
    int stop = num_2;
    for(int i = start; i <= stop; i++)
        printf("%d ", i);
    printf("\n");
}