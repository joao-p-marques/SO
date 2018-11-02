#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : 1);
}

int main(int argc, char *argv[])
{
    int i, numSize;
    int *numbers;
    int val;

    FILE *fd = fopen(argv[1], "r");
    numSize = 0;
    //First read to count the number of values to be stored
    while(fscanf(fd, "%d", &val)==1) //fscanf() reads an int and stores it in val. If not succesful, returns 0 or 1...
    {
        numSize++;
    }
    printf("Number of numbers: %d\n", numSize);
    rewind(fd);

    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);

    i = 0;
    while(fscanf(fd, "%d", &val)==1) //fscanf() reads an int and stores it in val. If not succesful, returns 0 or 1...
    {
        numbers[i++] = val;
    }
    numSize = i;

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
