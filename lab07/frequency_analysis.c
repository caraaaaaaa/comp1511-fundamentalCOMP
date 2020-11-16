// Lab07
// frequency_analysis.c
// Zixuan Guo (z513593)
// 02-04-2019

#include <stdio.h>

int main (int argc, char *argv[]) {
    int sum = 0;
    char ch = getchar();
    int ans[27] = {0};
    int i = 0;
    
    while (ch != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            sum++;
        }
        if (ch >= 'a' && ch <= 'z') {
            ans[ch - 'a' + 1]++;
        }
        if (ch >= 'A' && ch <= 'Z') {
            ans[ch - 'A' + 1]++;
        }
        ch = getchar();
    }
    
    i = 1;
    double freq;
    while (i < 27) {
        freq = (double) ans[i] / sum;
        printf("'%c' %6lf %d\n", i+96, freq, ans[i]);
        i++;
    }
}
