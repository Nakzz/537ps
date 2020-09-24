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

// constructor function for PID struct
struct pid *create_pid(char *id)
{

    if (_pid_exists(id))
    {
        struct pid *newPID;

        newPID = malloc(sizeof(struct pid)); //TODO: Do I have to clean this before ending my program? If should I should have a decontructor
        if(newPID == NULL){
            printf("%s","%i\n" "errno: ", errno);
            fprintf(stderr, "Error: %s\n", strerror( errno ));
            exit(-1);
        }
        //newPID->id = id;
        strcpy(newPID->id, id);
        newPID->exists = 1;
        //newPID->flag_p = 1;
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
    if(p.exists){
    //  printf("%s: %d %d %d %d %d %d\n", p.id, p.flag_s, p.flag_U, p.flag_S, p.flag_v, p.flag_c, p.flag_m);

    char *result_s = malloc(sizeof(char) * 50); // allocate memory on the heap

    if(result_s == NULL)
            exit(-1);

    char *result_U = malloc(sizeof(char) * 50); // allocate memory on the heap

       if(result_U == NULL)
            exit(-1);

    char *result_S = malloc(sizeof(char) * 50); // allocate memory on the heap

       if(result_S == NULL)
            exit(-1);

    char *result_v = malloc(sizeof(char) * 50); // allocate memory on the heap

       if(result_v == NULL)
            exit(-1);

    char *result_c = malloc(sizeof(char) * 50); // allocate memory on the heap

       if(result_c == NULL)
            exit(-1);

    // char *result_m = malloc(sizeof(char) * 50); // allocate memory on the heap
    //    if(result_m == NULL)
    //         exit(-1);


        get_flag_s(p, result_s); 
        get_flag_U(p, result_U); 
        get_flag_S(p, result_S);
        get_flag_v(p, result_v); 
        get_flag_c(p, result_c); 
        // get_flag_m(p, result_m);

     printf("%s: %s %s %s %s %s \n", p.id,  result_s, result_U, result_S, result_v, result_c);

     free(result_s);
     free(result_U);
     free(result_S);
     free(result_v);
     free(result_c);
    //  free(result_m);

    }
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
            // printf("FOUND PID: %s %d \n", procDir->d_name, procDir->d_type);
            return 1;
            break;
        }
    }

    return 0; //did not find the process
}


/*
    *
    * Returns pointer to the single-character state information about the process
    * 
    */
void get_flag_s(struct pid p, char * result)
{

    if (p.flag_s)
    {

        //call the helper method
         _getFieldfromStat(p.id, 3, result); ///proc/[pid]/stat (3) state  %c
    }

    // return " ";
}

/*
    *
    * Returns pointer to the amount of system time consumed so far by this process
    * 
    */
void get_flag_S(struct pid p, char * result)
{
    // char *result = malloc(sizeof(char) * 50); // allocate memory on the heap

    if (p.flag_S)
    {
        //call the helper method
        strcpy(result, "stime: ");
        _getFieldfromStat(p.id, 15, result); // /proc/[pid]/stat (15) stime  %lu
    
    }
}

/*
    *
    * Returns pointer to the amount of user time consumed so far by this process
    * 
    */
void get_flag_U(struct pid p, char * result)
{
    // char *result = malloc(sizeof(char) * 50); // allocate memory on the heap

    if (p.flag_U)
    {

        //call the helper method
        strcpy(result, "utime: ");
        _getFieldfromStat(p.id, 14, result);
    }

    // return "";
}

/*
    *
    * Returns pointer to the amount of virtual memory currently being used
    * 
    */
void get_flag_v(struct pid p, char * result)
{

    if (p.flag_v)
    {
        // char *result = malloc(sizeof(char) * 20); // allocate memory on the heap

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
            // putchar(ch);
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

        // char *temp = malloc(sizeof(char) * 50); // allocate memory on the heap

        // strcat(temp, result);

        // return temp;
    }

    // return "";
}

/*
    *
    * Returns pointer to the command-line that started this program
    * 
    */
void get_flag_c(struct pid p, char * result)
{
    if (p.flag_c)
    {
        // char *result = malloc(sizeof(char) * 20); // allocate memory on the heap 

        // char result[20];  // allocate memory on the stack
        //char *result = malloc(sizeof(char) *20); // allocate memory on the heap

        char path[20];

        strcpy(path, "/proc/");
        strcat(path, p.id);
        strcat(path, "/cmdline");

        /* File pointer to hold reference to our file */
        FILE *fPtr = malloc(sizeof(FILE));

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
            // putchar(ch);
            //printf("%d \n ", isspace(ch));

            result[i++] = ch;

        } while (ch != EOF); /* Repeat this if last read character is not EOF */

        /* Done with this file, close file to release resource */
if(fPtr)       
 fclose(fPtr);

        // printf("vmem is %s \n", result);

        // char *temp = malloc(sizeof(char) * 100); // allocate memory on the heap

        // strcpy(temp, "[ ");
        // strcat(temp, result);
        // strcat(temp, " ]");

        // return temp;
    }

    // return "";
}

/*
*   Returns pointer to the contents of a process's memory, starting at hexidecimal address 
*   addr and displaying decimal len bytes of information.
*
    */
void get_flag_m(struct pid p, char * result)
{
    //printf(" Id is: %d ,sFlag is: %d\n", p.id, p.flag_p);
    // char *result = malloc(sizeof(char) * 20); // allocate memory on the heap
    //char result[100];

    //printf(" Id is: %d ,pFlag is: %d\n", p.id, p.flag_p);

    if (p.flag_m)
    {
        strcpy(result, "todo: Extracredit m"); //TODO: Finish implementing
    }

    //return result;
}

//stat_index -1 is the index
void _getFieldfromStat(char *p, int stat_index, char * result)
{

    // char result[20];  // allocate memory on the stack
    //char *result = malloc(sizeof(char) * 20); // allocate memory on the heap

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

    //return result;
}
