#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randomPartition(int arr[], int start, int end) {
    srand(time(NULL));
    int randomIndex = start + rand() % (end - start + 1);
    swap(&arr[randomIndex], &arr[end]);
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

void randomQuickSort(int arr[], int start, int end) {
    if (start < end) {
        int p = randomPartition(arr, start, end);
        randomQuickSort(arr, start, p - 1);
        randomQuickSort(arr, p + 1, end);
    }
}

int main() {
    int arr[20], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    randomQuickSort(arr, 0, n - 1);

    printf("\nSorted array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
