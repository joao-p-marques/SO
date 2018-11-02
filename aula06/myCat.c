#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */

void remove_end_line(char * line)
{
    // char new_line[strlen(line) - 1];
    // for(int i = 0; i < strlen(line); i++)
    // {
    //     if(line[i]=='\n') break;
    //     new_line[i]=line[i];
    // }
    // return new_line;
    line[strlen(line)-1] = '\0';
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    /* Validate number of arguments */
    if(argc < 2)
    {
        printf("USAGE: %s fileName(s)\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */

    for(int i = 1; i < argc; i++)
    {
        errno = 0; //stores the error number of function fopen()
        fp = fopen(argv[i], "r");

        printf("File %s:\n", argv[i]);

        if(fp == NULL)
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        /* read all the lines of the file */
        int linec = 1;
        while(fgets(line, sizeof(line), fp) != NULL )
        {
            // printf("%d -> %s", linec, line);
            remove_end_line(line);
            printf("-> %s (%d)\n", line, linec);
            linec++;
        }

        printf("\n");
        fclose (fp);
    }
    

    return EXIT_SUCCESS;
}
