// Lab08 
// one_per_line
// Zixuan Guo (z5173593)

#include <stdio.h>

int main (void) {
    printf("Enter a string: ");
    
    char line[4096];
    int i = 0;
    fgets(line, 4096, stdin);
    while (line[i] != '\n') {
        i++;
    }
    
    if (i == 0) {
        printf("String is a palindrome\n");
    }
    
    int counter = 0;
    while (counter < (i / 2)) {
        if (line[counter] == line[i - counter - 1]) {
            counter++;
        } else {
            printf("String is not a palindrome\n");
            return 0;
        }
        
        if (counter == (i / 2)) {
            printf("String is a palindrome\n");
            return 0;
        } 
    }
}
