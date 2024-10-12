#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



#define TAMANHO 100




int jaExisteNumeros(int numeros[],int tamanho,int numero )
{
    for(int i = 0; i < tamanho; i++ )
    {
        if(numeros[i] == numero)
        {
            return 1;  // ja existe
        }
    }
    return 0;  /// nao existe
}



int main()
{

    // float a = 15.5;

    // float b = 10.5;

    // float result = (float) 15.4 / 10.4;

    // printf("%f",result);


    srand(time(NULL));

   


    int vetor[TAMANHO];
    int numero, i = 0;    // aqui i é 0 e numero nao foi inicializada, somente delcarada.

    int numero2 = rand() % 1000;
    int numero3 = rand() % 1000;
    int numero4 = rand() % 1000;
    int numero5 = rand() % 1000;

    printf("numeros aleatorios");
    printf("\n%d %d %d %d\n\n", numero2,numero3,numero4,numero5);



    while (i < TAMANHO)
    {
        numero = rand() % 1000 + 1;


        if (!jaExisteNumeros(vetor,i,numero))
        {
            vetor[i] = numero;
            i++;
        }
    }



    printf("Vetor de 100 números aleatórios e não repetidos:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;



}
