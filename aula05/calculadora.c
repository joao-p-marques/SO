#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        fprintf(stderr, "Número inválido de argumentos. (Esperados 3)\n");
        return EXIT_FAILURE;
    }

    // // 1ª implementação
    // double var1 = atof(argv[1]);
    // double var2 = atof(argv[3]);

    // 2ª implementação
    char *pc1, *pc2;
    double var1 = strtod(argv[1], &pc1);
    double var2 = strtod(argv[3], &pc2);
    char op = *argv[2];
    double res;

    if(*pc1 != '\0' || *pc2 != '\0')
    {
        //erro de conversão
        fprintf(stderr, "Valor inválido! Insira apenas valores numéricos.\n");
        return EXIT_FAILURE;
    }

    switch(op)
    {
        case '+':
            res = var1 + var2;
            break;
        case '-':
            res = var1 - var2;
            break;
        case 'x':
            res = var1 * var2;
            break;
        case '/':
            res = var1 / var2;
            break;
        case 'p':
            res = pow(var1, var2); //precisa de #include <math.h> e de flag -lm no compilador
            break;
        default:
            fprintf(stderr, "Operação inválida!\n");
            return EXIT_FAILURE;
    }

    printf("%.1f %c %.1f = %.1f", var1, op, var2, res);
    return EXIT_SUCCESS;
}