#include <stdio.h>   // biblioteca padrao de entrada e saida
#include <string.h>
#include <stdlib.h>
#include <time.h>



#define TAMANHO 100   // SEM INT SEM ; bizarro kkkkkk



struct Alunos
{
    char nome[50];
    long long int matricula;

} Aluno;


 
int jaExisteNumeros(int numeros[],int tamanho,int numero )
{
    for(int i = 0; i < tamanho; i++ )
    {
        if(numeros[i] == numero)
        {
            return 1;  // ja existe'
        }
    }
    return 0;  /// nao existe
}



int main()
{
    strcpy(Aluno.nome, "Arthur Guerra");
    Aluno.matricula = 202208901000;
    printf("Quem fez o código: %s\n", Aluno.nome);
    printf("Matrícula: %lld\n", Aluno.matricula);

    int ultimoDigito1 = Aluno.matricula % 10;

    //printf("Ultimo digito de Aluno: %d\n", ultimoDigito1);

    struct Alunos Aluno2;

    strcpy(Aluno2.nome, "Irineu");
    Aluno2.matricula = 1000000001;
    printf("\nInutil 1 : %s\n", Aluno2.nome);
    printf("Matrícula: %lld\n", Aluno2.matricula);

    int ultimoDigito2 = Aluno2.matricula % 10;

    struct Alunos Aluno3;

    strcpy(Aluno3.nome, "Voce nao sabe");
    Aluno3.matricula = 10000000001;
    printf("\nInutil 2 : %s\n", Aluno3.nome);
    printf("Matrícula: %lld\n", Aluno3.matricula);

    int ultimoDigito3 = Aluno3.matricula % 10;

    struct Alunos Aluno4;

    strcpy(Aluno4.nome, "Nem eu");
    Aluno4.matricula = 10000000001;
    printf("\nInutil 3 : %s\n", Aluno4.nome);
    printf("Matrícula: %lld\n", Aluno4.matricula);

    int ultimoDigito4 = Aluno4.matricula % 10;

    struct Alunos Aluno5;

    strcpy(Aluno5.nome, "KEWK");
    Aluno5.matricula = 100000001;
    printf("\nInutil 4 : %s\n", Aluno5.nome);
    printf("Matrícula: %lld\n", Aluno5.matricula);

    int ultimoDigito5 = Aluno5.matricula % 10;

    int sum = (ultimoDigito1 + ultimoDigito2 + ultimoDigito3 + ultimoDigito4 + ultimoDigito5) % 3;

    printf("Resultado da soma de: %d %d %d %d %d ( modulo ) 3  = %d\n\n", ultimoDigito1,ultimoDigito2,ultimoDigito3,ultimoDigito4,ultimoDigito5,sum);


    // Semente para o gerador de números aleatórios
    srand(time(NULL));

    int vetor[TAMANHO];
    int numero, i = 0;    // aqui i é 0 e numero nao foi inicializada, somente declarada.

    clock_t inicio = clock();   // começa a medir o tempo

    while (i < TAMANHO)
    {
        numero = rand() % 1000 + 1;

        if (!jaExisteNumeros(vetor,i,numero))
        {
            vetor[i] = numero;
            i++;
        }
    }

    printf("Numeros de 0 a 100 sem repetição\n");

    for(int i =0; i < TAMANHO; i++)
    {
        printf("%d - ", vetor[i]);
    }


    if ( sum == 0 )
    {
        // bubble sort lento  nao indicado a listas grandes

        int flag = 1;       // 1 é true e 0 é false
        int count = 0;

        while(flag) 
        {
            flag = 0;

            for(int i =0; i < TAMANHO - 2; i++ ) 
            {
                if(vetor[i] > vetor[i+1])
                {
                    int aux = vetor[i];
                    vetor[i] = vetor[i+1];

                    vetor[i+1] = aux;

                    flag = 1;
                    count++;
                    // GENIAL
                }
            }
        }

        printf("\n\nMethod: Bubble Sort !\n ");
        for(int i =0; i < TAMANHO ; i++)
        {
            printf("\nNúmero: %d - %d ", i+1 , vetor[i]);
            
        }
        clock_t fim = clock();
        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("\nQuantidade de comparações: %d", count);
        printf("\nTempo de Execução: %.6lf", tempo_execucao);

    }

    else if (sum == 1)
    {
     
        int count = 0;      // 1 é true e 0 é false

        for(int i =0; i < TAMANHO - 1; i++ ) 
        {
            int menorIndex = i;   // vetor[0] = 10 exemplo

            for (int j = i + 1; j < TAMANHO; j++)
            {
                count++; 
                if(vetor[j] < vetor[menorIndex])  // vetor[j] = 10   e vetor[0] = 20
                {
                    menorIndex = j;                  
                }                         
            }

            if(menorIndex != i)
            {
                int aux = vetor[i];
                vetor[i] = vetor[menorIndex];
                vetor[menorIndex] = aux;
            }                  
        }

        
        

        printf("\n\nMethod: Selection Sort !\n ");
        for(int i =0; i < TAMANHO ; i++)
        {
            printf("\nitem: %d - %d ", i+1 , vetor[i]);
            
        }
        clock_t fim = clock();
        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("\nQuantidade de comparações: %d", count);
        printf("\nTempo de Execução: %.6lf", tempo_execucao);


    }
    else
    {
       printf("\nnumero 2 ou mais");
        
    }

   
   return 0;
   
}
