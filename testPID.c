/*C program to get Process Id and Parent Process Id in Linux.*/
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main()
{
    int p_id;
     
    p_id=getpid();  /*process id*/
     
    
    int *result = malloc(sizeof(int) * 20); // allocate memory on the heap

    while(1){
        result = rand();
         printf("Process ID: %d  rand:%d at &%d \n",p_id, result, &result);



        sleep(5);


    }
    return 0;
}