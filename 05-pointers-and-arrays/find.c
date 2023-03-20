#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long line_no = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch(c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    fprintf(stderr, "find: illegal option %c\n", c);
                    exit(1);

            }
        }
    }

    if (argc != 1) {
        fprintf(stderr, "Usage: find -x -n pattern\n");
        exit(1);
    } else {
        while (fgets(line, MAXLINE, stdin) != NULL) {
            line_no++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld:", line_no);
                }
                printf("%s", line);
                found++;
            }
        }
    }

    return 0;
}
