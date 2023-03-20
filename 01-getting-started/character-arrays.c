#include <stdio.h>
#define MAX 1000

/* function prototypes */
int get_line(char line[], int maxline);
void copy(char dest[], char src[]);

/* print longest input line */
int main(void) {
    int len = 0, max = 0;
    char line[MAX];
    char longest[MAX];

    while ((len = get_line(line, MAX)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s\n", longest);
    }

    return 0;
}

/* read a line into array, return length */
int get_line(char line[], int max) {
    char c;
    int idx;

    for (idx = 0; idx < max - 1 && (c = getchar()) != EOF && c != '\n'; idx++) {
        line[idx] = c;
    }

    if (c == '\n') {
        line[idx++] = c;
    }

    line[idx] = '\0';
    return idx;
}

/* copy src to dest */
void copy(char dest[], char src[]) {
    for (int i = 0; (dest[i] = src[i]) != '\0'; i++)
        ;
}
