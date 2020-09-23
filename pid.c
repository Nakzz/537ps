///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	pid.c
//
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#include "pid.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

// constructor function for PID struct
struct pid *create_pid(char *id)
{

    if (_pid_exists(id))
    {
        struct pid *newPID;

        newPID = malloc(sizeof(struct pid)); //TODO: Do I have to clean this before ending my program? If should I should have a decontructor
        //newPID->id = id;
        strcpy(newPID->id, id);
        newPID->exists = 1;
        newPID->flag_p = 1;
        newPID->flag_c = 1; //This option defaults to be true
        newPID->flag_U = 1; //This option defaults to be true
        newPID->flag_S = 0; //This option defaults to be false
        newPID->flag_v = 0; //This option defaults to be false
        newPID->flag_m = 0; //This option defaults to be false

        return newPID;

    } //TODO: should we be throwing error message if it doesn't exist?
    else
    {
        return NULL;
    }
}

/*
    * Prints the information for given PID based on flags.
    * For example:
    *       537ps -p 1234 -s -U -c
    *   This runs your ps command, and displays the status letter (in this case, running), 
    *   amount of user time, and the command line for process 1234. 
    *   You might expect the output to look like: 1234: R utime=150 [myprog -x -y file1 myoption] 
    */
void printPID(struct pid p)
{
    printf("%s: %s %s %s %s %s %s\n", p.id, get_flag_s(p), get_flag_U(p), get_flag_S(p), get_flag_v(p), get_flag_c(p), get_flag_m(p));
}

/*
    * Reads the /proc directory and checks if process existings
    * 
    * 
    */
int _pid_exists(char *id)
{

    DIR *directory = opendir("/proc");

    // Unable to open directory stream
    if (!directory)
        return;

    struct dirent *procDir;

    while ((procDir = readdir(directory)) != NULL)
    {
        if (strcmp(procDir->d_name, id) == 0)
        {
            printf("FOUND PID: %s %d \n", procDir->d_name, procDir->d_type);
            return 1;
            break;
        }
    }

    return 0; //did not find the process
}

//TODO: consider removing
char *get_flag_p(struct pid p)
{
    char *result = malloc(sizeof(char) * 20); // allocate memory on the heap
    //char result[100];

    //printf(" Id is: %d ,pFlag is: %d\n", p.id, p.flag_p);

    if (p.flag_p)
    {
        strcpy(result, "todo: p"); //TODO: Finish implementing
    }

    return result;
}

/*
    *
    * Returns pointer to the single-character state information about the process
    * 
    */
char *get_flag_s(struct pid p)
{

    if (p.flag_s)
    {

        //call the helper method
        return _getFieldfromStat(p.id, 3); ///proc/[pid]/stat (3) state  %c
    }

    return " ";
}

/*
    *
    * Returns pointer to the amount of system time consumed so far by this process
    * 
    */
char *get_flag_S(struct pid p)
{
    char *result = malloc(sizeof(char) * 50); // allocate memory on the heap

    if (p.flag_S)
    {

        //call the helper method
        strcpy(result, "stime: ");
        return strcat(result, _getFieldfromStat(p.id, 15)); // /proc/[pid]/stat (15) stime  %lu
    }

    return "";
}

/*
    *
    * Returns pointer to the amount of user time consumed so far by this process
    * 
    */
char *get_flag_U(struct pid p)
{
    char *result = malloc(sizeof(char) * 50); // allocate memory on the heap

    if (p.flag_s)
    {

        //call the helper method
        strcpy(result, "utime: ");
        return strcat(result, _getFieldfromStat(p.id, 14)); ///proc/[pid]/stat (14) utime  %lu
    }

    return "";
}

/*
    *
    * Returns pointer to the amount of virtual memory currently being used
    * 
    */
char *get_flag_v(struct pid p)
{

    if (p.flag_v)
    {
        char *result = malloc(sizeof(char) * 20); // allocate memory on the heap

        // char result[20];  // allocate memory on the stack
        //char *result = malloc(sizeof(char) *20); // allocate memory on the heap

        char path[20];

        strcpy(path, "/proc/");
        strcat(path, p.id);
        strcat(path, "/statm");

        /* File pointer to hold reference to our file */
        FILE *fPtr;

        char ch;

        /* 
     * Open file in r (read) mode. 
     * "data/file1.txt" is complete file path to read
     */
        fPtr = fopen(path, "r");

        /* fopen() return NULL if last operation was unsuccessful */
        if (fPtr == NULL)
        {
            /* Unable to open file hence exit */
            printf("Unable to open file.\n");
            printf("Please check whether file exists and you have read privilege.\n");
            exit(EXIT_FAILURE);
        }

        int i = 0;
        do
        {
            /* Read single character from file */
            ch = fgetc(fPtr);

            /* Print character read on console */
            // strcat(result, ch);
            putchar(ch);
            //printf("%d \n ", isspace(ch));

            if (isspace(ch) != 0)
            {
                break;
            }

            result[i++] = ch;

        } while (ch != EOF); /* Repeat this if last read character is not EOF */

        /* Done with this file, close file to release resource */
        fclose(fPtr);

        // printf("vmem is %s \n", result);

        char *temp = malloc(sizeof(char) * 50); // allocate memory on the heap

        strcpy(temp, "vmem: ");
        strcat(temp, result);

        return temp;
    }

    return "";
}

/*
    *
    * Returns pointer to the command-line that started this program
    * 
    */
char *get_flag_c(struct pid p)
{
    if (p.flag_c)
    {
        char *result = malloc(sizeof(char) * 20); // allocate memory on the heap

        // char result[20];  // allocate memory on the stack
        //char *result = malloc(sizeof(char) *20); // allocate memory on the heap

        char path[20];

        strcpy(path, "/proc/");
        strcat(path, p.id);
        strcat(path, "/cmdline");

        /* File pointer to hold reference to our file */
        FILE *fPtr;

        char ch;

        /* 
     * Open file in r (read) mode. 
     * "data/file1.txt" is complete file path to read
     */
        fPtr = fopen(path, "r");

        /* fopen() return NULL if last operation was unsuccessful */
        if (fPtr == NULL)
        {
            /* Unable to open file hence exit */
            printf("Unable to open file.\n");
            printf("Please check whether file exists and you have read privilege.\n");
            exit(EXIT_FAILURE);
        }

        int i = 0;
        do
        {
            /* Read single character from file */
            ch = fgetc(fPtr);

            /* Print character read on console */
            // strcat(result, ch);
            putchar(ch);
            //printf("%d \n ", isspace(ch));

            result[i++] = ch;

        } while (ch != EOF); /* Repeat this if last read character is not EOF */

        /* Done with this file, close file to release resource */
        fclose(fPtr);

        // printf("vmem is %s \n", result);

        char *temp = malloc(sizeof(char) * 100); // allocate memory on the heap

        strcpy(temp, "[ ");
        strcat(temp, result);
        strcat(temp, " ]");

        return temp;
    }

    return "";
}

/*
*   Returns pointer to the contents of a process's memory, starting at hexidecimal address 
*   addr and displaying decimal len bytes of information.
*
    */
char *get_flag_m(struct pid p)
{
    //printf(" Id is: %d ,sFlag is: %d\n", p.id, p.flag_p);
    char *result = malloc(sizeof(char) * 20); // allocate memory on the heap
    //char result[100];

    //printf(" Id is: %d ,pFlag is: %d\n", p.id, p.flag_p);

    if (p.flag_m)
    {
        strcpy(result, "todo: Extracredit m"); //TODO: Finish implementing
    }

    return result;
}

//stat_index -1 is the index
char *_getFieldfromStat(char *p, int stat_index)
{

    // char result[20];  // allocate memory on the stack
    char *result = malloc(sizeof(char) * 20); // allocate memory on the heap

    char path[20];

    strcpy(path, "/proc/");
    strcat(path, p);
    strcat(path, "/stat");

    /* File pointer to hold reference to our file */
    FILE *fPtr;

    char ch;

    /* 
     * Open file in r (read) mode. 
     * "data/file1.txt" is complete file path to read
     */
    fPtr = fopen(path, "r");

    /* fopen() return NULL if last operation was unsuccessful */
    if (fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    stat_index--; // adjusting index, since parameter coming in follows PS
    int i = -1;
    do
    {
        /* Read single character from file */
        ch = fgetc(fPtr);

        /* Print character read on console */
        // strcat(result, ch);
        //putchar(ch);
        //printf("%d \n ", isspace(ch));

        if (isspace(ch) != 0)
        {
            stat_index--;
        }
        //TODO: add ch to some holder

        if (stat_index < 0)
        {
            break;
        }
        else if (stat_index == 0)
        {

            // putchar(ch);
            // sprintf(ch, "%d", ch);
            // strcpy(result, ch);
            if (i >= 0)
                result[i] = ch;
            i++;
        }

    } while (ch != EOF); /* Repeat this if last read character is not EOF */

    /* Done with this file, close file to release resource */
    fclose(fPtr);

    // printf("done parsing %s \n ", result);
    // printf("%s", result);

    return result;
}
