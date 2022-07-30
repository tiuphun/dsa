#include <stdio.h>
void swap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void MinHeapify(int A[], int i, int n){//Array started from index 1
    int leftChild = 2*i;
    int rightChild = 2*i + 1;
    int indexMin = i;
    if (leftChild <= n && A[leftChild] < A[indexMin]) indexMin = leftChild;
    if (rightChild <= n && A[rightChild] < A[indexMin]) indexMin = rightChild;
    if (i != indexMin){//A[i] violates min heap properties
        swap(A[indexMin], A[i]);
        MinHeapify(A, indexMin, n);
    }
}
void BuildMinHeap(int A[], int n){
    for (int i = n/2; i >= 1; i--) MinHeapify(A, i, n);
}
void HeapSort(int A[], int n){
    BuildMinHeap(A, n);
    for (int i = n; i >= 2; i--)
    {
        swap(A[1], A[i]);
        MinHeapify(A, 1, n-1);
    }
}