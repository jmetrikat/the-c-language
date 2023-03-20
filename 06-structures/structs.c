#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

struct point makepoint(int x, int y) {
    struct point tmp;

    tmp.x = x;
    tmp.y = y;
    return tmp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

void multpoint(struct point *p, int n) {
    p->x *= n;
    p->y *= n;
}

int main(void) {
    struct point p1 = makepoint(0, 0);
    struct point p2 = makepoint(1, 2);

    printf("p1 before:\t %2d %2d\n", p1.x, p1.y);
    p1 = addpoint(p1, p2);
    printf("p1 after add:\t %2d %2d\n", p1.x, p1.y);

    printf("p2 before:\t %2d %2d\n", p2.x, p2.y);
    multpoint(&p2, 10);
    printf("p2 after mul:\t %2d %2d\n", p2.x, p2.y);

    return 0;
}
