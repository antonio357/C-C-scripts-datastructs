#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node;

typedef struct {
    node* begin;
    int len; // modificação do desafio
} list;

list* createlist(); // Criação da lista (createList);

void print_list(list* l); // Impressão na tela dos valores armazenados por todos os elementos da lista (printList);

int list_len(list* l); // Verificar a quantidade de elementos presentes na lista (size).

void append(list* l, int value); // Inserção no fim da lista (add)

void drop_begin(list* l);

void clear_list(list* l);

void del_list(list* l);

int remove_value(list* l, int val); // Retira um elemento, dado o valor do elemento como parâmetro (removeElement);

int its_empty(list* l); // Verificação se a lista está vazia (isEmpty);

int remove_last(list* l); // Remoção no fim da lista (removeBack);

int has_element(list* l, int val); // Verificar se um determinado elemento existe dentro da lista (hasElement);

int insert_position(list* l, int val, int position); // Inserir um elemento em qualquer local da lista (insertPosition);

int remove_position(list* l, int position); // Remover um elemento de qualquer local da lista (removePosition);

int get(list* l, int* p, int position); // Obter o valor de um elemento da lista (get)

// 4. Desafio