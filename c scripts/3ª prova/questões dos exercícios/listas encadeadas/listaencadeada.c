#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

list* createlist() { // Criação da lista (createList);
    list* l = (list*)malloc(sizeof(list));
    l->begin = NULL;
    l->len = 0; // modificação do desafio
    return l;
}

int list_len(list* l) { // Verificar a quantidade de elementos presentes na lista (size).
    /*int len = 0;
    if (l->begin == NULL) return len;
    node* support = l->begin;
    len++;
    while(support->next != NULL) {
        len++;
        support = support->next;
    }*/
    return l->len; // modificação do desafio
}

void append(list* l, int value) { // Inserção no fim da lista (add)
    l->len += 1; // modificação do desafio
    node* support = l->begin;
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    if (l->begin == NULL) {
        l->begin = new_node;
        return;
    }
    while(support->next != NULL) {
        support = support->next;
    }
    support->next = new_node;
    return;
}

void print_list(list* l) { // Impressão na tela dos valores armazenados por todos os elementos da lista (printList);
    node* support = l->begin;
    printf("[");
    if (l->begin != NULL) {
        while (support->next != NULL) {
            printf("%d, ", support->value);
            support = support->next;
        }
        printf("%d", support->value);
        printf("]\n");
        //printf("pointer of the last node -> %p\n", support->next);
        printf("mod. do desafio -> list_len = %d\n", l->len); // modificação do desafio
        return;
    }
    printf("]\n");
    //printf("pointer of the last node -> %p\n", support);
    printf("mod. do desafio -> list_len = %d\n", l->len); // modificação do desafio
    return;
}

void drop_begin(list* l) {
    if (l->begin == NULL) return;
    node* support = l->begin;
    l->begin = l->begin->next;
    free(support);
    l->len -= 1; // modificação do desafio
    return;
}

int remove_value(list* l, int val) { // Retira um elemento, dado o valor do elemento como parâmetro (removeElement);
    if (l->begin == NULL) return -1;
    node* support = l->begin;
    node* previous_support = NULL;
    int count = 0;
    while(support->next != NULL && support->value != val) {
        previous_support = support;
        support = support->next;
        count++;
    }
    if (support->value == val) {
        if (count == 0) {
            l->begin = support->next;
            free(support);
        }
        else if (count > 0) {
            previous_support->next = support->next;
            free(support);
        }
        l->len -= 1; // modificação do desafio
        return count;
    }
    else return -1;
}

int its_empty(list* l) { // Verificação se a lista está vazia (isEmpty);
    if (l->begin == NULL) return 1;
    return 0;
}

int remove_last(list* l) { // Remoção no fim da lista (removeBack);
    if (l->begin == NULL) return -1; // quando não tem o que remover;
    node* support = l->begin;
    node* previous_support = NULL;
    while (support->next != NULL) {
        previous_support = support;
        support = support->next;
    }
    if (previous_support == NULL) {
        l->begin = NULL;
        free(support);
    }
    else {
        previous_support->next = NULL;
        free(support);
    }
    l->len -= 1; // modificação do desafio
    return 0; // quando a lista tinha pelo menos um elemento e foi possivel realizar a operassao
}

int has_element(list* l, int val) { // Verificar se um determinado elemento existe dentro da lista (hasElement);
    int element_position = -1;
    int count = 0;
    if (l->begin == NULL) return element_position;
    node* support = l->begin;
    if (support->next == NULL) {
        if (support->value == val) return 0;
        else return -1; 
    }
    while(support->next != NULL) {
        if (support->value == val) {
            element_position = count;
            break;
        }
        else if (support->next->value == val) element_position = count + 1;
        support = support->next;
        count++;
    }
    //if (support->value == val) element_position = count;
    return element_position;
}

int insert_position(list* l, int val, int position) { // Inserir um elemento em qualquer local da lista (insertPosition);
    int len = list_len(l);
    if (position < 0 || position > len) return -1;
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    if (l->begin == NULL) {
        if (position == 0) {
            l->begin = new_node;
            l->len += 1; // modificação do desafio
            return 0;
        }
        else return -1;
    }
    else if (l->begin->next == NULL) {
        if (position <= 1) {
            if (position == 0) {
                new_node->next = l->begin;
                l->begin = new_node;
                l->len += 1; // modificação do desafio
                return 0;
            }
            else if (position == 1) {
                l->begin->next = new_node;
                l->len += 1; // modificação do desafio
                return 0;
            }
        }
        else return -1;
    }
    node* support = l->begin;
    node* previous_support = NULL;
    int counter = 0;
    while(support->next != NULL && counter < position) {
        previous_support = support;
        support = support->next;
        counter++;
    }
    if (position == 0) {
        new_node->next = support;
        l->begin = new_node;
    }
    else if (position < len) {
        new_node->next = support;
        previous_support->next = new_node;
    }
    else if (position == len) {
        support->next = new_node;
    }
    l->len += 1; // modificação do desafio
    return 0;
}

void clear_list(list* l) {
    node* support = l->begin;
    node* next_support = l->begin->next;
    if (l->begin == NULL) return;
    else if (l->begin->next == NULL) {
        free(support);
        l->begin = NULL;
        l->len -= 1; // modificação do desafio
        return;
    } 
    while(support->next != NULL) {
        free(support);
        support = next_support; 
        if (next_support != NULL) next_support = next_support->next;
    }
    l->len = 0; // modificação do desafio
    l->begin = NULL;
}

void del_list(list* l) {
    clear_list(l);
    free(l);
}

int remove_position(list* l, int position) { // Remover um elemento de qualquer local da lista (removePosition);
    int len = list_len(l);
    if (position < 0 || position >= len) return -1;
    if (l->begin == NULL) return -1;
    int counter = 0;
    node* support = l->begin;
    node* previous_support = NULL;
    if (len == 1) {
        if (position == 0) {
            l->begin = NULL;
            free(support);
            l->len -= 1; // modificação do desafio
            return 0;
        }
        else return -1;
    }
    else if (len == 2) {
        if (len == 0) {
            l->begin = support->next;
            free(support);
            l->len -= 1; // modificação do desafio
            return 0;
        }
        else if (len == 1) {
            previous_support = support;
            support = support->next;
            previous_support->next = NULL;
            free(support);
            l->len -= 1; // modificação do desafio
            return 0;
        }
        else return -1;
    }
    while (support->next != NULL && counter < position) {
        counter++;
        previous_support = support;
        support = support->next;
    }
    if (position == 0) {
        l->begin = support->next;
        free(support);
    }
    else if (position <  len) {
        previous_support->next = support->next;
        free(support); 
    }
    l->len -= 1; // modificação do desafio
    return 0;
}

int get(list* l, int* p, int position) { // Obter o valor de um elemento da lista (get)
    *p = 0;
    int len = list_len(l);
    if (l->begin == NULL || position < 0 || position >= len) return -1;
    if (len == 1) {
        if (position == 0) *p = l->begin->value;
        return 0;
    }
    else if (len == 2) {
        if (position == 0) *p = l->begin->value;
        else if (position == 1) *p = l->begin->next->value;
        return 0;
    }
    int counter = 0;
    node* support = l->begin;
    while (support->next != NULL && counter < position) {
        support = support->next;
        counter++;
    }
    *p = support->value;
    return 0;
}