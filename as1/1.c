#include <stdio.h>

int check_coco (int num1, int num2, int array[], int coco[]);

int main(void) {
    int a = 9;
    int c = 18;
    int arr[5] = {12, 13, 14, 15, 11};
    int co[10];
    int b = check_coco (a, c, arr, &co[10]);
    printf("%d", b);
    return 0;
}


int check_coco (int num1, int num2, int array[], int coco[]) {
    int i = 2;
    int f = 0;
    int factor[10];
    while (i < num1) {
        if (num1 % i == 0) {
            factor[f] = i;
            f++;
        }
        i++;
    }
    
    int c = 0;
    int a = 0;
    int b = 0;
    while (a < num2) {
        while (b < f) {
            if (array[a] % factor[b] == 0) {
                coco[c] = array[a];
                c++;
                return 1;
            } else {
                b++;
            }
        }
        b = 0;
        a++;
    }
    return 0;
}
