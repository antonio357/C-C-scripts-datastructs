#include<stdio.h>
#include<string.h>

int main() {
    char s1[100]; char s2[100]; char s3[100];

    scanf("%s", s1);
    scanf("%s", s2); 
    scanf("%s", s3);

    if (strcmp(s1,"vertebrado") == 0 && strcmp(s2, "ave") == 0 && strcmp(s3, "carnivoro") == 0) {
        printf("aguia\n");}
    else if (strcmp(s1, "vertebrado") == 0 && strcmp(s2, "ave") == 0 && strcmp(s3, "onivoro") == 0) {
        printf("pomba\n");}

    else if (strcmp(s1, "vertebrado") == 0 && strcmp(s2, "mamifero") == 0 && strcmp(s3, "onivoro") == 0) {
        printf("homem\n");}
    else if (strcmp(s1, "vertebrado") == 0 && strcmp(s2, "mamifero") == 0 && strcmp(s3, "herbivoro") == 0) {
        printf("vaca\n");}


    else if (strcmp(s1, "invertebrado") == 0 && strcmp(s2, "inseto") == 0 && strcmp(s3, "hematofago") == 0) {
        printf("pulga\n");}
    else if (strcmp(s1, "invertebrado") == 0 && strcmp(s2, "inseto") == 0 && strcmp(s3, "herbivoro") == 0) {
        printf("lagarta\n");}

    else if (strcmp(s1, "invertebrado") == 0 && strcmp(s2, "anelideo") == 0 && strcmp(s3, "hematofago") == 0) {
        printf("sanguessuga\n");}
    else if (strcmp(s1, "invertebrado") == 0 && strcmp(s2, "anelideo") == 0 && strcmp(s3, "onivoro") == 0) {
        printf("minhoca\n");}

    return 0;
}
