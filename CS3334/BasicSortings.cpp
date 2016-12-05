#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

const int n = 1000;
int arr[n];
int temp[n];

void init() {
    for (int i = 0;i < n;i++)
        arr[i] = n - i * 2;
}
void print() {
    for (int i = 0;i < n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}
bool sorted() {
    for (int i = 0;i < n - 1;i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

void bubbleSort() {
    for (int i = 0;i < n;i++)
        for (int j = n - 1;j > i;j--)
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}
void insertionSort() {
    for (int i = 1;i < n;i++)
        for (int j = i;j > 0 && arr[j] < arr[j - 1];j--)
            swap(arr[j], arr[j - 1]);
}
void mergeSort(int lo, int hi) {
    //int temp[n];
    if (lo >= hi)
        return;
    int mid = (lo + hi) >> 1;
    mergeSort(lo, mid);
    mergeSort(mid + 1, hi);

    int i = lo, j = mid + 1, k = lo;
    while (i <= mid&&j <= hi)
        (arr[i] < arr[j]) ? temp[k++] = arr[i++] : temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= hi)
        temp[k++] = arr[j++];
    for (i = lo;i <= hi;i++)
        arr[i] = temp[i];
}
int partition(int lo, int hi) {
    int pivot = arr[lo];
    int L = lo, R = hi;
    while (1) {
        while (arr[R] >	pivot) R--;
        while (arr[L] < pivot) L++;
        if (L >= R)
            return R;
        swap(arr[L], arr[R]);
    }
}
void quickSort(int lo, int hi) {
    if (lo >= hi)
        return;
    int p = partition(lo, hi);
    quickSort(lo, p);
    quickSort(p + 1, hi);
}
void sorting(int c) {
    clock_t start = clock();
    switch (c) {
        case 1:
            printf("Bubble Sort: O(n^2)\n");
            bubbleSort();
            break;
        case 2:
            printf("Insertion Sort: O(n^2)\n");
            insertionSort();
            break;
        case 3:
            printf("Merge Sort: O(n*logn) | space O(n)\n");
            mergeSort(0, n - 1);
            break;
        case 4:
            printf("Quick Sort: worst O(n^2) avg O(n*logn)\n");
            quickSort(0, n - 1);
            break;
    }
    double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    printf("Time: %lf\n", duration);
}
void core() {
    for (int c = 1;c <= 4;c++) {
        init();
        sorting(c);
    }
}

int main() {
    init();
    core();
    if (sorted()) {
        printf("Done\n");
    } else {
        print();
    }
    return 0;
}