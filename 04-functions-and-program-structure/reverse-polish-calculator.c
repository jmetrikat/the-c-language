#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        fprintf(stderr, "ungetch: too many characters\n");
        exit(1);
    } else {
        buf[bufp++] = c;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
    }

    /* not a number */
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }

    /* integer part */
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
        }
    }

    /* fraction part */
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
        }
    }
    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        fprintf(stderr, "Error: stack full, can't push %g\n", f);
        exit(1);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
}

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    fprintf(stderr, "Error: zero divisor\n");
                    exit(1);
                }
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                fprintf(stderr, "Error: unknown command %s\n", s);
                exit(1);
        }
    }

    return 0;
}
