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

        newPID = malloc(sizeof(struct pid));
        if(newPID == NULL)
        {
            printf("%s\n", "Error: Bad Malloc");
            exit(-1);
        }

        strcpy(newPID->id, id);
        newPID->exists = 1;
        newPID->flag_c = 1; //This option defaults to be true
        newPID->flag_U = 1; //This option defaults to be true
        newPID->flag_S = 0; //This option defaults to be false
        newPID->flag_v = 0; //This option defaults to be false
        newPID->flag_m = 0; //This option defaults to be false

        return newPID;
    }
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
    if (p.exists)
    {
        printf("%s: ", p.id);

        get_flag_s(p);
        get_flag_U(p);
        get_flag_S(p);
        get_flag_v(p);
        get_flag_c(p);

        printf(" \n");
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
        return 0;

    struct dirent *procDir;

    while ((procDir = readdir(directory)) != NULL)
    {
        if (strcmp(procDir->d_name, id) == 0)
        {
            return 1;
            break;
        }
    }
    closedir(directory);
    return 0; //did not find the process
}

/*
    *
    * Returns pointer to the single-character state information about the process
    * 
    */
void get_flag_s(struct pid p)
{

    if (p.flag_s)
    {
        //call the helper method
        _getFieldfromStat(p.id, 3); ///proc/[pid]/stat (3) state  %c
        printf(" ");
    }
}

/*
    *
    * Returns pointer to the amount of system time consumed so far by this process
    * 
    */
void get_flag_S(struct pid p)
{
    if (p.flag_S)
    {
        printf("%s", "stime: ");

        _getFieldfromStat(p.id, 15); // /proc/[pid]/stat (15) stime  %lu
        printf(" ");
    }
}

/*
    * Returns pointer to the amount of user time consumed so far by this process
    */
void get_flag_U(struct pid p)
{

    if (p.flag_U)
    {

        //call the helper method
        printf("%s", "utime: ");
        _getFieldfromStat(p.id, 14);
        printf(" ");
    }

    // return "";
}

/*
    * Returns pointer to the amount of virtual memory currently being used
    */
void get_flag_v(struct pid p)
{

    if (p.flag_v)
    {

        char path[20];

        strcpy(path, "/proc/");
        strcat(path, p.id);
        strcat(path, "/statm");

        /* File pointer to hold reference to our file */
        FILE *fPtr;

        char ch;

        /* 
     * Open file in r (read) mode. 
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

        // int i = 0;
        do
        {
            /* Read single character from file */
            ch = fgetc(fPtr);

            if (isspace(ch) != 0)
            {
                break;
            }

            // result[i++] = ch;
            printf("%c", ch);

        } while (ch != EOF); /* Repeat this if last read character is not EOF */

        /* Done with this file, close file to release resource */
        fclose(fPtr);
        printf(" ");
    }
}

/*
    *
    * Returns pointer to the command-line that started this program
    * 
    */
void get_flag_c(struct pid p)
{
    if (p.flag_c)
    {
        printf("%c", '[');

        char path[20];

        strcpy(path, "/proc/");
        strcat(path, p.id);
        strcat(path, "/cmdline");

        /* File pointer to hold reference to our file */
        FILE *fPtr;
        // = malloc(sizeof(FILE));

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

        do
        {
            /* Read single character from file */
            ch = fgetc(fPtr);

            if (isascii(ch) != 0)
                printf("%c", ch);

        } while (ch != EOF); /* Repeat this if last read character is not EOF */

        /* Done with this file, close file to release resource */

        fclose(fPtr);

        printf("%c", ']');
    }
}

/*
*   Returns pointer to the contents of a process's memory, starting at hexidecimal address 
*   addr and displaying decimal len bytes of information.
*/
void get_flag_m(struct pid p)
{

    if (p.flag_m)
    {
        // strcpy(result, "todo: Extracredit m"); //TODO: Finish implementing
    }
}

/*
* Helper method to read word from /proc/
* stat_index -1 is the index in the file
*/
void _getFieldfromStat(char *p, int stat_index)
{

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

        if (isspace(ch) != 0)
        {
            stat_index--;
        }

        if (stat_index < 0)
        {
            break;
        }
        else if (stat_index == 0)
        {

            // putchar(ch);
            if (i >= 0)
            {
                printf("%c", ch);
            }
            i++;
        }

    } while (ch != EOF); /* Repeat this if last read character is not EOF */

    /* Done with this file, close file to release resource */
    fclose(fPtr);
}

void freePID(struct pid **list, int size){
	for(int i=0; i<size; i++){
			if(list[i] != NULL){
			free(list[i]);
		}
	}
    free(list);
}
