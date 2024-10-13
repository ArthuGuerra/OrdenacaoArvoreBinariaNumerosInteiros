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


/*


    Descrição dos campos:
    int valor;  --------- Esse campo é usado para armazenar um valor inteiro associado ao nó. Em uma árvore binária, geralmente esse valor é o dado que queremos organizar na estrutura.

    struct No *esquerdo, *direito;   ==  Esses são dois ponteiros que apontam para os filhos do nó atual:

    esquerdo: Aponta para o filho da esquerda do nó, ou seja, o próximo nó na subárvore esquerda.
    direito: Aponta para o filho da direita do nó, ou seja, o próximo nó na subárvore direita.

    Como eles são do tipo struct No*, eles referenciam outros nós da mesma estrutura, permitindo que os nós se conectem e formem a árvore.



*/


typedef struct no 
{
    int conteudo;   // campo para armazenar um valor inteiro 
    struct no *esquerdo, *direito;  // dois PONTEIROS para outros nós da arvore ( filho esquerdo e filho direito );
    //int valor2; // outro campo para armazenar um segundo valor inteiro ???
}No;


typedef struct
{
    No *raiz;
} Arvb;


void inserirDireita(No *no, int valor);

void inserirEsquerda(No *no, int valor)
{
    if(no->esquerdo ==NULL)
    {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo -> esquerdo = NULL;
        novo -> direito = NULL;
        no->esquerdo = novo;
    }
    else
    {
        if(valor < no->esquerdo-> conteudo)
        {
            inserirEsquerda(no->esquerdo,valor);
        }
        else
        {
            inserirDireita(no->esquerdo,valor);
        }
    }
}

void inserirEsquerda(No *no, int valor);

void inserirDireita(No *no, int valor)
{
    if(no->direito == NULL)
    {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo -> esquerdo = NULL;
        novo -> direito = NULL;
        no-> direito = novo;

    }
    else
    {
        if(valor > no->direito->conteudo)
        {
            inserirDireita(no->direito,valor);
        }
        else
        {
            inserirEsquerda(no->direito,valor);
        }
    }
}



void inserir(Arvb *arv, int valor)
{
    if(arv->raiz == NULL)
    {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo -> esquerdo = NULL;
        novo -> direito = NULL;
        arv -> raiz = novo;
    }
    else 
    {
        if(valor < arv ->raiz->conteudo)
        {
            inserirEsquerda(arv->raiz, valor);
        }
        else
        {
            inserirDireita(arv-> raiz,valor);
        }
    }
}




void imprimir(No *raiz)
{
    if(raiz != NULL)
    {
        printf("\nraiz: %d ", raiz->conteudo);

        imprimir(raiz->esquerdo);
        imprimir(raiz->direito);
    }
}




int main()
{
    strcpy(Aluno.nome, "Arthur Guerra");
    Aluno.matricula = 202208901069;
    printf("Quem fez o código: %s\n", Aluno.nome);
    printf("Matrícula: %lld\n", Aluno.matricula);

    int ultimoDigito1 = Aluno.matricula % 10;

    //printf("Ultimo digito de Aluno: %d\n", ultimoDigito1);

    struct Alunos Aluno2;

    strcpy(Aluno2.nome, "Irineu");
    Aluno2.matricula = 222222222222;
    printf("\nInutil 1 : %s\n", Aluno2.nome);
    printf("Matrícula: %lld\n", Aluno2.matricula);

    int ultimoDigito2 = Aluno2.matricula % 10;

    struct Alunos Aluno3;

    strcpy(Aluno3.nome, "Voce nao sabe");
    Aluno3.matricula = 333333333333;
    printf("\nInutil 2 : %s\n", Aluno3.nome);
    printf("Matrícula: %lld\n", Aluno3.matricula);

    int ultimoDigito3 = Aluno3.matricula % 10;

    struct Alunos Aluno4;

    strcpy(Aluno4.nome, "Nem eu");
    Aluno4.matricula = 444444444444;
    printf("\nInutil 3 : %s\n", Aluno4.nome);
    printf("Matrícula: %lld\n", Aluno4.matricula);

    int ultimoDigito4 = Aluno4.matricula % 10;

    struct Alunos Aluno5;

    strcpy(Aluno5.nome, "KEWK");
    Aluno5.matricula = 555555555555;
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
        
         // 1 é true e 0 é false
      
        int countComparacao = 0;
        for(int i =1; i < TAMANHO; i++ ) 
        {
            int atual = vetor[i];
            int j = i -1;
            
            while (j >= 0 && vetor[j] > atual)
            {             
                vetor[j+1] = vetor[j];
                j--;
                countComparacao++;            
            }
           
           vetor[j + 1 ] = atual;
            
        }
        

        printf("\n\nMethod: Insection Sort !\n ");
        for(int i =0; i < TAMANHO ; i++)
        {
            printf("\nNúmero: %d - %d ", i+1 , vetor[i]);
            
        }
        clock_t fim = clock();
        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("\nQuantidade de comparações: %d", countComparacao);
        printf("\nTempo de Execução: %.6lf", tempo_execucao);

        
    }


    printf("\n\nAgora nossa linda árvore binária. ");
     

    Arvb minhaArvore;
    minhaArvore.raiz = NULL;

    for(int i= 0; i<TAMANHO; i++)
    {
       inserir(&minhaArvore,vetor[i]);
    }

    imprimir(minhaArvore.raiz);


    // for(int i = 0; i < TAMANHO; i++)
    // {
    //     if(Arvore.principal == 0)
    //     {
    //         Arvore.principal = vetor[i];
    //     }
    //     else
    //     {
    //         if(vetor[i] > Arvore.principal)
    //         {

    //             if(Arvore.direito->principal == 0)
    //             {
    //                 Arvore.direito->principal = vetor[i];
    //             }
    //             else
    //             {
    //                 if (vetor[i] < Arvore.direito->principal)
    //                 {
    //                     Arvore.direito->esquerdo = vetor[i];
    //                     Arvore.direito->esquerdo->principal = Arvore.direito->esquerdo;
    //                 }
    //                 else
    //                 {
    //                     Arvore.direito->direito = vetor[i];
    //                     Arvore.direito->direito->principal = Arvore.direito->direito;
    //                 }
    //             }

    //         }           
    //         else
    //         {
    //              if(Arvore.esquerdo->principal == 0)
    //             {
    //                 Arvore.esquerdo->principal = vetor[i];
    //             }
    //             else
    //             {
    //                 if (vetor[i] < Arvore.esquerdo->principal)
    //                 {
    //                     Arvore.esquerdo->esquerdo = vetor[i];
    //                     Arvore.esquerdo->esquerdo->principal = Arvore.esquerdo->esquerdo;
    //                 }
    //                 else
    //                 {
    //                     Arvore.esquerdo->direito = vetor[i];
    //                     Arvore.esquerdo->direito->principal = Arvore.esquerdo->direito;
    //                 }
    //             }
    //         }
    //     }
    //     i++;  
    //}

   
   return 0;
   
}
