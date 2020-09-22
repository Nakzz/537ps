/*C program to get Process Id and Parent Process Id in Linux.*/
 
#include <stdio.h>
#include <unistd.h>
 
int main()
{
    int p_id;
     
    p_id=getpid();  /*process id*/
     


    while(1){
         printf("Process ID: %d\n",p_id);
        sleep(5);
    }
    return 0;
}