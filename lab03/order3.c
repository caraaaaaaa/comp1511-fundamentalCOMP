// lab03
// order3
// Zixuan Guo z5173593

#include <stdio.h>

int main (void) {
    int a;
    int b;
    int c;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    
    printf("The integers in order are: ");
    
    if (a <= b && b <= c) {
        printf("%d %d %d", a, b, c);
    } else if (a <= c && c <= b) {
        printf("%d %d %d", a, c, b);
    } else if (b <= a && a <= c) {
        printf("%d %d %d", b, a, c);
    } else if (b <= c && c <= a) {
        printf("%d %d %d", b, c, a);
    } else if (c <= a && a <= b) {
        printf("%d %d %d", c, a, b);
    } else {
        printf("%d %d %d", c, b, a);
    }
    
    printf("\n");
    return 0;
}
