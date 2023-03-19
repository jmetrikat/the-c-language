#include <stdio.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                int tmp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = tmp;
            }
        }
    }
}

int main(void) {
    int arr[] = {12, 42, 1, 5, 9, 7};

    shellsort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
