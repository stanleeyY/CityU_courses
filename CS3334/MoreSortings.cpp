#include <queue>
using namespace std;
//Heap
int A[100];
int size;
void pushDown(int i) {// to push A[i] down to its correct position
    int y = A[i];
    int hole = i, child = 2 * hole;
    while (child <= size) {
        if (child < size && A[child] > A[child + 1])
            child++; // child points to smaller one
        if (A[child] >= y) break;
        A[hole] = A[child];
        hole = child;
        child = 2 * hole; // point to the left child
    }
    A[hole] = y;
}
void insert(int x) {
    size++;
    int hole = size;
    while (hole > 1 && x < A[hole / 2]) {
        A[hole] = A[hole / 2];
        hole = hole / 2;
    }
    A[hole] = x;
}
int deleteMin() {
    int min = A[1];
    A[1] = A[size];
    size--;
    pushDown(1);
    return min;
}
void buildHeap(int n) {// to arrange A[1..n] in heap order
    size = n;
    for (int i = n / 2; i >= 1; i--)
        pushDown(i);
}
void heapSort(int n) {
    buildHeap(n);
    for (int i = n; i >= 2; i--)
        A[i]=deleteMin();
    for (int i = 1, j = n; i < j; i++, j--)
        swap(A[i], A[j]);
}
//bucket_sort, stable_sort, radix_sort
void bucketSort(int arr[],int n){
    int dp[1000];//should be equal to the max value of all the values
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[arr[i]]++;
    int k=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<dp[i];j++)
            arr[k++]=i;
    }
}
void radixSort(int arr[],int n) {
    queue<int> s[10];
    for (int i = 0; i < n; i++)
        s[arr[i] % 10].push(arr[i]);
    for (int i = 0, k = 0; i < 10; i++)
        while (!s[i].empty()) {
            arr[k++] = s[i].front();
            s[i].pop();
        }
    for (int i = 0; i < n; i++)
        s[(arr[i] / 10) % 10].push(arr[i]);
    for (int i = 0, k = 0; i < 10; i++)
        while (!s[i].empty()) {
            arr[k++] = s[i].front();
            s[i].pop();
        }
    for (int i = 0; i < n; i++)
        s[(arr[i] / 100) % 10].push(arr[i]);
    for (int i = 0, k = 0; i < 10; i++)
        while (!s[i].empty()) {
            arr[k++] = s[i].front();
            s[i].pop();
        }
}