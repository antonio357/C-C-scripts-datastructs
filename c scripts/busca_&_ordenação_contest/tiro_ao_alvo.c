#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

int module(int num) {
    if (num >= 0) return num;
    else return num * -1;
}

int its_in(int radius, int x, int y) {
    if (module(x) > radius || module(y) > radius) return False;
    return True;
}

void scored(int *score, int position_vet_radius) {
    *score += position_vet_radius + 1;
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
    //printf("median = %d\n", center_position);
    return center_position;
}

int binary_search_by_position(const int vet_radius_f[], int position_from_smallest_radius, int x, int y) {
    int first_position = 0; int last_position = position_from_smallest_radius;
    int return_position;
    //printf("\nbefore get inside the loop\n");
    printf("first_position = %d, last_position = %d\n", first_position, last_position);
    //printf("inside the loop\n");
    if (its_in(vet_radius_f[first_position], x, y) == True) return_position = first_position;
    //if (its_in(vet_radius[last_position], x, y) == True) return_position = last_position;
    while((last_position - first_position) > 1) {
        if (its_in(vet_radius_f[median(first_position, last_position)], x, y) == True) first_position = median(first_position, last_position);
        else last_position = median(first_position, last_position);
        //printf("after interaction\n");
        printf("first_position = %d, last_position = %d\n", first_position, last_position);
    }
    if (its_in(vet_radius_f[first_position], x, y) == True) return_position = first_position;
    if (its_in(vet_radius_f[last_position], x, y) == True) return_position = last_position;
    printf("return_position = %d\n", return_position);
    return return_position;
}

int main() {
    int q_circles = 0; int q_shoots = 0; int total_ps = 0;
    scanf("%d %d", &q_circles, &q_shoots);

    int *vet_radius = (int*)malloc(q_circles*sizeof(int));
    int *vet_shoots = (int*)malloc(q_shoots*2*sizeof(int));
    if (vet_shoots == NULL || vet_radius == NULL) {
      printf("erro\n");
      return - 1;
    }

    int i = 0;
    for (i = q_circles - 1; i >= 0; i--) {
        scanf("%d", &vet_radius[i]);
    }
    for (i = 0; i < q_shoots*2; i += 2) {
        scanf("%d %d", &vet_shoots[i], &vet_shoots[i + 1]);
    }
    for (i = 0; i < q_shoots*2; i += 2) {
        // it's out of the biggest circle 
        if (its_in(vet_radius[0], vet_shoots[i], vet_shoots[i + 1]) == False) {
            printf("coordinate = (%d, %d)\n", vet_shoots[i], vet_shoots[i + 1]);
            printf("it's not inside any circle\n");
            printf("total_ps = %d\n", total_ps);
            continue;
        }
        // it's inside de smallest circle
        if (its_in(vet_radius[q_circles - 1], vet_shoots[i], vet_shoots[i + 1]) == True) {
            scored(&total_ps, q_circles - 1);
            printf("coordinate = (%d, %d)\n", vet_shoots[i], vet_shoots[i + 1]);
            printf("it's inside the smallest circle\n");
            printf("total_ps = %d\n", total_ps);
            continue;
        }
        // binary_search
        printf("coordinate = (%d, %d)\n", vet_shoots[i], vet_shoots[i + 1]);
        scored(&total_ps, binary_search_by_position(vet_radius, q_circles - 1, vet_shoots[i], vet_shoots[i + 1]));
        printf("total_ps = %d\n", total_ps);
    }
    printf("%d\n", total_ps);
    free(vet_radius);
    free(vet_shoots);
    return 0;
}