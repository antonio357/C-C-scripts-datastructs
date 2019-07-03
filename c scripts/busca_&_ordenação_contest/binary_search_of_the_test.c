#include<stdio.h>
#include<stdlib.h>

typedef struct {
    double altura;
    char nome[30];
} modelo;

double module(double x);
int busca_binaria(const modelo *vet, double h, int len);
int c_busca_binaria(const modelo *vet, double h, int len);

int main() {
    int n, i = 0; double hi = 0;
    scanf("%d", &n); scanf("%lf", &hi);
    modelo *vet = (modelo*)malloc(n*sizeof(modelo));
    for (i = 0; i < n; i++) scanf("%s %lf", vet[i].nome, &vet[i].altura);
    printf("%s\n", vet[c_busca_binaria(vet,hi,n)].nome);
    return 0;
}

double module(double x) {
    if (x < 0) return x * -1;
    return x;
}

int busca_binaria(const modelo *vet, double h, int len) {
    int b = 0, e = len - 1, p_of_ch = e, m;
    double b_h = vet[b].altura, e_h = vet[e].altura, m_h = vet[m].altura, pofch_h = vet[p_of_ch].altura;
    while(e - b >= 2) {
        m = (b + e)/2;
        b_h = vet[b].altura; e_h = vet[e].altura; m_h = vet[m].altura; pofch_h = vet[p_of_ch].altura;
        if (module(b_h - h) < module(pofch_h - h)) p_of_ch = b;
        if (module(e_h - h) < module(pofch_h - h)) p_of_ch = e;
        if (module(m_h - h) < module(pofch_h - h)) p_of_ch = m;
        if (m_h < h) b = m;
        else if (m_h > h) e = m;
        else return m;
    }
    return p_of_ch;
}

int c_busca_binaria(const modelo *vet, double h, int len) {
    if (len >= 3) return busca_binaria(vet,h,len);
    else if (len == 1) return 0;
    else if (len == 2) {
        if (module(vet[0].altura - h) < module(vet[1].altura - h)) return 0;
        return 1;
    }
}