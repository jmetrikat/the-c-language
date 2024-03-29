#include <stdio.h>

/* function prototype */
int binsearch(int x, int v[], int n);

/* test binsearch */
int main(void) {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int x = 5;
    printf("%d\n", binsearch(x, v, n));
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
