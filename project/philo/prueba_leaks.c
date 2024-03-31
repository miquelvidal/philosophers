#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    *prueba;
    size_t  size;

    size = 1000;
    prueba = (char *)malloc(size);
    if(prueba == NULL)
        return (0);
    prueba[size - 1] = '\0';
    
    printf("Hola mundo! _%s_ \n", prueba);
    exit(EXIT_SUCCESS);
    //return (0);
}