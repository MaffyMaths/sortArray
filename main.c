#include <stdio.h>
#include <malloc.h>

void printArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

int* inputArray(int n) {
    int *arr;
    arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        printf("arr[%d] =", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error in scanning Array value\n");
            return 0;
        }
    }
    return arr;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr[j] > arr[j + 1] && arr[j] >= 0 && arr[j + 1] >= 0) || (arr[j] < 0)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < 0 && arr[j + 1] < 0 && arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    printf("Input size of array:");
    int n = 0;
    if (scanf("%d", &n) != 1) {
        printf("Error in scanning N value\n");
        return 0;
    }
    int* arr = inputArray(n);
    if (!arr) return 0;

    sortArray(arr, n);

    printf("\nSorted array is:\n");
    printArray(arr, n);
    free(arr);
    return 0;
}
