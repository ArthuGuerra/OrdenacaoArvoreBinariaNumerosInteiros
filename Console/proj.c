#include <stdio.h>   // biblioteca padrao de entrada e saida
#include <string.h>
#include <stdlib.h>
#include <time.h>


const int TAMANHO = 100;


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
    int conteudo  --------- Esse campo é usado para armazenar um valor inteiro associado ao nó. Em uma árvore binária, geralmente esse valor é o dado que queremos organizar na estrutura.

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
        No *novo = (No*)malloc(sizeof(No));     // malloc = alocar memoria para esse novo nó 
        if(novo ==NULL)
        {
            return;
        }
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
        printf("\nraiz: %d ", raiz->conteudo);      /* ele pode pedir pra alterar aqui. Desse jeito ta em Pré ordem. primeiro a raiz, esquerda e direita*/ 
        imprimir(raiz->esquerdo);                   ///  em ordem  é esquerda, raiz e direita. 
        imprimir(raiz->direito);                    /// e pos ordem é a nossa, esquerda, direita e raiz
                                                    //// ele pode pedir pra alterar essa primeira impressao em alguma outra ordem por exemplo
    }
}




void pos_ordem(No *no_pos)
{

    if(no_pos == NULL)  /// e se o nó for nulo, a função simplesmente retorna (para evitar acessar ponteiros nulos).
    {
        return;
    }
    if(no_pos -> esquerdo != NULL)   /// Se o nó esquerdo existe, a função chama recursivamente a si mesma para processar a subárvore esquerda.
    {
        pos_ordem(no_pos->esquerdo);
    }
     if(no_pos -> direito != NULL)  //  Se o nó direito existe, a função chama recursivamente a si mesma para processar a subárvore direita.
    {
        pos_ordem(no_pos->direito);
    }
    printf("\n%d", no_pos->conteudo);
}


void percorrer_pos_ordem(Arvb *arvore)
{
    if(arvore -> raiz != NULL )
    {
        pos_ordem(arvore->raiz);
    }
}


////// ----------------------------------------------------------------------------//// 

int main()
{
    strcpy(Aluno.nome, "Arthur Guerra");
    Aluno.matricula = 202208901069;
    printf("Aluno 1: %s\n", Aluno.nome);
    printf("Matrícula: %lld\n", Aluno.matricula);

    int ultimoDigito1 = Aluno.matricula % 10;

    //printf("Ultimo digito de Aluno: %d\n", ultimoDigito1);

    struct Alunos Aluno2;

    strcpy(Aluno2.nome, "Alice Louise ");
    Aluno2.matricula = 202302375189;
    printf("\nAluno 2 : %s\n", Aluno2.nome);
    printf("Matrícula: %lld\n", Aluno2.matricula);

    int ultimoDigito2 = Aluno2.matricula % 10;

    struct Alunos Aluno3;

    strcpy(Aluno3.nome, "Paulo");
    Aluno3.matricula = 202302450873;
    printf("\nAluno 3 : %s\n", Aluno3.nome);
    printf("Matrícula: %lld\n", Aluno3.matricula);

    int ultimoDigito3 = Aluno3.matricula % 10;

    struct Alunos Aluno4;

    strcpy(Aluno4.nome, "Eduardo Vinicius");
    Aluno4.matricula = 202302674712;
    printf("\nAluno 4 : %s\n", Aluno4.nome);
    printf("Matrícula: %lld\n", Aluno4.matricula);

    int ultimoDigito4 = Aluno4.matricula % 10;

    struct Alunos Aluno5;

    strcpy(Aluno5.nome, "João Pedro");
    Aluno5.matricula = 202103689809;
    printf("\nAluno 5 : %s\n", Aluno5.nome);
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
        numero = rand() % 1000 + 1;     // pode mudar aqui 

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

    
    // criando um vetor nao ordenado para a arvore
    int vetorArvore[TAMANHO];


    for(int i = 0; i < TAMANHO; i++)
    {
        vetorArvore[i] = vetor[i];
    }


    if ( sum == 0 )
    {
        //  bubble sort lento  nao indicado a listas grandes 
        //  compara o 1 item com o segundo item
        //  agora o segundo com o terceiro e assim por diante
        //

        int flag = 1;       // 1 é true e 0 é false
        int count = 0;

        while(flag) 
        {
            flag = 0;

            for(int i =0; i <= TAMANHO - 2; i++ ) 
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
     
        // compara as 2 primeiras posiçoes, no caso 0 e 1
        // depois ele compara o 0 com o proximo, no caso o 2 


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

        // O laço começa na segunda posição do vetor (i = 1), porque o primeiro elemento (posição 0) já pode ser considerado como ordenado.
  
        // Em cada iteração, o algoritmo pega o valor da posição atual (atual = vetor[i]) e o insere no lugar correto nos elementos anteriores que já estão ordenados.
      
        int countComparacao = 0;
        for(int i =1; i < TAMANHO; i++ ) 
        {
            int atual = vetor[i];  // atual = 10
            int j = i -1;
            
            while (j >= 0 && vetor[j] > atual)   // vetor[ i ]  = 10     vetor[ j ] = 15
            {             
                vetor[j+1] = vetor[j];
                j--;
                countComparacao++;            
            }
           
           vetor[j + 1 ] = atual;
            
        }

        int countNumeros = 1;
        
        printf("\n\nMethod: Insection Sort !\n ");
        for(int i =0; i < TAMANHO - 1; i++)
        {
            printf("\nNúmero: %d - %d ", i+1 , vetor[i]);
            countNumeros++;
            
        }
        clock_t fim = clock();
        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("\nQuantidade de comparações: %d", countComparacao);
        printf("\nTempo de Execução: %.10lf", tempo_execucao);
        printf("\n\nQuantidade de raizes: %d ", countNumeros);
     
    }


    printf("\n\nAgora nossa linda árvore binária. ");
     

    Arvb minhaArvore;
    minhaArvore.raiz = NULL;
    int countNumeros = 1;

    for(int i= 0; i<TAMANHO-1; i++)
    {
       inserir(&minhaArvore,vetorArvore[i]);
       countNumeros++;

       // O uso do & nesse caso é para passar o endereço de memória da variável minhaArvore para a função inserir
    }

    imprimir(minhaArvore.raiz);



    printf("Quantidade de raizes: %d ", countNumeros);


    printf("\n\nAgora nossa linda árvore binária Pós-Ordem ");


    percorrer_pos_ordem(&minhaArvore);
   
   return 0;
   
}
