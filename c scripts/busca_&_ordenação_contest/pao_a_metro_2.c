#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

int q_sands(int vet[], int len_vet , int len_sand) {
    int q_sand = 0;
    int i = 0;
    for (i = 0; i < len_vet; i++) {
        if (len_sand == 0) break;
        if (vet[i] >= len_sand) q_sand += (int)vet[i]/len_sand;
    }
    return q_sand;
}

int median(int begin, int end) {
    int center_position;
    int len = (end - begin) + 1;
    if (len%2 == 0) {
       center_position = (int)((end + begin)/2);
    }
    else if (len%2 != 0) {
       center_position = (begin + end)/2;
    }
    return center_position;
}

int binary_search(int vet[], int vet_len, int biggest_num_vet, int q_ps) {
    int return_value = 0; int begin = 1; int end = biggest_num_vet; 
    int return_value_last = return_value;

    if (q_sands(vet, vet_len, 1) >= q_ps) return_value = 1;
    else if (q_sands(vet, vet_len, biggest_num_vet) >= q_ps) return_value = biggest_num_vet;

    while((end - begin) > 1) {
        //printf("begin = %d, end = %d, median = %d, q_sands = %d\n", begin, end, median(begin, end), q_sands(vet, vet_len, median(begin, end)));
        if (q_sands(vet, vet_len, median(begin, end)) >= q_ps) {
            return_value = median(begin, end);
            begin = median(begin, end);
        }
        else {end = median(begin, end);}
    }
    return return_value;
}

int main () {
    int q_ps;
    int vet_len; 
    int biggest_num_vet;
    int i = 0;

    scanf("%d", &q_ps);
    scanf("%d", &vet_len);

    int *vet = (int*)malloc(vet_len*sizeof(int));
    if (vet == NULL) {
        printf("didn't allocated the vector\n");
        return - 1;
    }

    for (i = 0; i < vet_len; i++) {
        scanf("%d", &vet[i]);
        if (i == 0) {
            biggest_num_vet = vet[i];
        }
        else if (i > 0 && vet[i] > biggest_num_vet) {
            biggest_num_vet = vet[i];
        } 
    } 
    printf("%d\n", binary_search(vet, vet_len, biggest_num_vet, q_ps));
    //printf("fim = %d\n", biggest_num_vet);
    //int lis1[2] = {45, 85};
    //printf("ok = %d\n", q_sands(lis1,2,42));
    //printf("%d\n", q_sands(lis,k,595));
    return 0;
}