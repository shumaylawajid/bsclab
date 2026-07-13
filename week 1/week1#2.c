#include <stdio.h>
#include <string.h>

int main() {
    char str[100], word[20], result[100] = "";
    char *p;
    printf("Enter string: "); gets(str);
    printf("Enter word to remove: "); gets(word);

    p = strtok(str, " ");
    while (p != NULL) {
        if (strcmp(p, word) != 0) {
            strcat(result, p);
            strcat(result, " ");
        }
        p = strtok(NULL, " ");
    }
    printf("Result: %s\n", result);
    return 0;
}

