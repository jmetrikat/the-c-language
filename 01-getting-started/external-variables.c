#include <stdio.h>
#define MAX 1000

/* external variables */
int max;
char line[MAX];
char longest[MAX];

/* function prototypes */
int get_line(void);
void copy(void);

/* print longest input line */
int main(void) {
    int len = 0;
    extern int max;
    extern char longest[MAX];

    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0) {
        printf("%s\n", longest);
    }

    return 0;
}

/* read a line into array, return length */
int get_line(void) {
    char c;
    int idx;
    extern char line[];

    for (idx = 0; idx < MAX - 1 && (c = getchar()) != EOF && c != '\n'; idx++) {
        line[idx] = c;
    }

    if (c == '\n') {
        line[idx++] = c;
    }

    line[idx] = '\0';
    return idx;
}

/* copy src to dest */
void copy(void) {
    extern char line[], longest[];

    for (int i = 0; (longest[i] = line[i]) != '\0'; i++)
        ;
}
