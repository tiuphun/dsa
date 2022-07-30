/*  Max Heap => increasing order
    Min Heap => decreasing order
 */
#include <stdio.h>
#define N 100
int A[N]; 
int n; //number of elements in the array
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//A - ARRAY STARTED IN INDEX 1
    int leftChild = 2*i;
    int rightChild = 2*i + 1;
    (Same idea as below, please be careful of the variable values.)
    

//B - ARRAY STARTED IN INDEX 0 - CHECKED
/***MAX HEAP***/
void MaxHeapify(int A[], int i, int heapSize){//Array started from index 0
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int indexMax = i;
    if (leftChild < heapSize && A[leftChild] > A[indexMax]) indexMax = leftChild;
    if (rightChild < heapSize && A[rightChild] > A[indexMax]) indexMax = rightChild;
    if (i != indexMax){//A[i] violates max heap properties
        swap(&A[indexMax], &A[i]);
        MaxHeapify(A, indexMax, n);
    }
}
void BuildMaxHeap(int A[], int heapSize){
    for (int i = (heapSize - 1)/2; i >= 0; i--) MaxHeapify(A, i, heapSize);
}
void MaxHeapSort(int A[], int heapSize){
    BuildMaxHeap(A, heapSize);
    for (int i = heapSize-1; i >= 0; i--)
    { 
        swap(&A[0], &A[i]); 
        MaxHeapify(A, 0, i-1);
    }
}

/***MIN HEAP***/
void MinHeapify(int A[], int i, int heapSize){//Array started from index 0
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int indexMin = i;
    if (leftChild < heapSize && A[leftChild] < A[indexMin]) indexMin = leftChild;
    if (rightChild < heapSize && A[rightChild] < A[indexMin]) indexMin = rightChild;
    if (i != indexMin){//A[i] violates min heap properties
        swap(&A[indexMin], &A[i]);
        MinHeapify(A, indexMin, n);
    }
}
void BuildMinHeap(int A[], int heapSize){
    for (int i = (heapSize - 1)/2; i >= 0; i--) MinHeapify(A, i, heapSize);
}
void MinHeapSort(int A[], int heapSize){
    BuildMinHeap(A, heapSize);
    for (int i = heapSize-1; i >= 0; i--)
    { 
        swap(&A[0], &A[i]); 
        MinHeapify(A, 0, i-1);
    }
}