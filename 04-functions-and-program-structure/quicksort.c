#include <stdio.h>

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* quicksort: sort v[left]...v[right] into increasing order */
void quicksort(int v[], int left, int right) {
    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    int last = left;

    for (int i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    quicksort(v, left, last - 1);
    quicksort(v, last + 1, right);
}

int main(void) {
    int arr[] = {12, 42, 1, 5, 9, 7};

    quicksort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
