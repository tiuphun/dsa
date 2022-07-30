#include <stdio.h>
#define N 100
int A[N];
void swap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void MaxHeapify(int A[], int i, int n){//Array started from index 1
    int leftChild = 2*i;
    int rightChild = 2*i + 1;
    int indexMax = i;
    if (leftChild <= n && A[leftChild] > A[indexMax]) indexMax = leftChild;
    if (rightChild <= n && A[rightChild] > A[indexMax]) indexMax = rightChild;
    if (i != indexMax){//A[i] violates max heap properties
        swap(A[indexMax], A[i]);
        MaxHeapify(A, indexMax, n);
    }
}
void BuildMaxHeap(int A[], int n){
    for (int i = n/2; i >= 1; i--) MaxHeapify(A, i, n);
}
void HeapSort(int A[], int n){
    BuildMaxHeap(A, n);
    for (int i = n; i >= 2; i--)
    {
        swap(A[1], A[i]);
        MaxHeapify(A, 1, n-1);
    }
}