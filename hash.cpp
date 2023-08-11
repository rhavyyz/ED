#include <iostream>

using namespace std;

typedef struct 
{
    int studentNumber;
} student;

typedef struct {
    int qtd, table_size;
    student **items;
} Hash;

Hash * createHash(int size);

void freeHash(Hash * h);

int toString(char * str);

int insertNoCollision(Hash * h, student a);

student * searchNoCollision(Hash * h, int key);

int insertOpenAddress(Hash * h, student a);

student * searchOpenAddress(Hash * h, int key);


///////////// Metodos de hashing ///////////////

// Objetivos:  
//      Garantir que chaves diferentes gerem valores diferentes
//
//      Buscar o maior nivel de espalhamento possivel no vetor

int DivisionKey(int key, int size)
{
    return (key & 0x7FFFFFFF) % size;
}

int multiplicationKey(int key, int size)
{
    float a = 0.6180339887; // constante fracionaria
    float val = key * a;
    val -= (int) val;
    return size * val;
}

int foldKey(int key, int size)
{
    int k = 5;

    int parte1 = key >> k,
        parte2 = key & (size - 1);

    return parte1 ^ parte2;
}

int stringAsKey(char * key, int size)
{
    int i =-1, val = 7;
    while(i++, key[i] != '\0')
        val = 31 * val + (int) key[i];

    return val;
}

// Hashing universal:
//  Atrelar a uma funcao de divisao valores constantes arbitrarias para cada hash nova criada
//  sendo elas

//  p, a, b de modo:

//  0 <= k < p // sendo k qualquer valor arbitrario de chave inserida na tabela 

//  0 < a <= p 
//  0 <= b <= p

// h(k) = ((a*k + b) % p) % table_size

//

Hash * createHash(int size)
{
    Hash * h = (Hash *) malloc(sizeof(Hash));

    if(h == NULL) return h;

    h->table_size = size;

    h->itens = (student **) calloc(h->table_size, sizeof(student *));


}

void freeHash(Hash * h)
{  
    for (int i = 0; i < h->table_size; i++)
    {
        if(h->items[i] != NULL)
            free(h->items[i]);
    }

    free(h);
}

int insertNoCollision(Hash * h, student a)
{
    if(h == NULL || h->qtd == h->table_size)
        return 0;

    int pos = DivisionKey(a.studentNumber, h->table_size);

    student * s = (student *) malloc(sizeof(a));

    if (s == NULL)
        return 0;
    
    *s = a;
    
    h->items[pos] = s;
    h->qtd++;

    return 1;
}

student * searchNoCollision(Hash * h, int key)
{
    if(h == NULL)
        return 0;

    int pos = DivisionKey(key, h->table_size);
    return h->items[pos];
}

int main()
{


    return 0;
}

// Hashing perfeito e imperfeito
//
//  Hashing perfeito é quando existe a garantia de quando não existem colisões na tabela em questão
//  Busca sempre O(1)
//  Conhecemos previamente o conteudo a ser armazenado ? (pode ser fake essa linha)

//  Hashing imperfeio é quando existem colisões na tabela 
//  Essas colisões normalmente sao gerenciadas com o uso de outras estruturas de dados


// Formas de tratar colisões
//  Endereçamento aberto 
//    Quando se depara com uma colisão tenta buscar outras posicoes na tabela para armazenar o elemento
//    Evita o uso de listas encadedas
//    Aumenta a necessidade de processamento na inserção, sendo O(N)

//  Encadeamento separado
//    Usar o lista encadeada nas posicoes do array e armazenar elementos conforme sao inseridos e colidem