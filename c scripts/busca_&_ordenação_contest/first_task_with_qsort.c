#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char str[51];
    int peso;
} str_p;

int compara_tamanhos(const void *p1, const void *p2) {
    //tem o mesmo tamanho
    if (strlen(p1) ==  strlen(p2)) {
        printf("p1 = %s == p2 = %s\n", p1, p2);
        str_p *p1_ = (str_p*)(p1);
        str_p *p2_ = (str_p*)(p2);
        if (p1_->peso >= p2_->peso) return 1;
        else if (p1_->peso < p2_->peso) return -1;
    }
    // primeira palavra > segunda palavra
    else if (strlen(p1) > strlen(p2)) {
      printf("p1 = %s > p2 = %s\n", p1, p2);
      return 1;
    }
    // primeira palavra < segunda palavra
    else if (strlen(p1) < strlen(p2)) {
      printf("p1 = %s < p2 = %s\n", p1, p2);
      return -1;
    }
}

//qsort 

int main() {
    int n;
    scanf("%d", &n);
    str_p vet_str_p[n]; 
    for (int i = 0; i < n; i++) {
        scanf("%s %d", vet_str_p[i].str, &vet_str_p[i].peso);
    } 
    qsort(vet_str_p, n, sizeof(str_p), compara_tamanhos); 
    for (int i = 0; i < n; i++) {
        printf("%s ", vet_str_p[i].str);
    }
    return 0;
}