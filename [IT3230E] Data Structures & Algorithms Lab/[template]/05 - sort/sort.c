//A compilation of all sorting function based on sorting techniques.
#include <stdio.h>
#include <stdlib.h> //This library contains all the sorting functions already.
#define SIZE 100
int a[SIZE];

//SELECTION SORT - CHECKED
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void SelectionSort(int a[], int n){
    int i, j, index_min;
    for (i = 0; i < n-1; i++){
        index_min = i;
        for (j = i+1; j < n; j++)
        if (a[j] < a[index_min]) index_min = j;
        swap(&a[i], &a[index_min]);
    } 
}

//MERGE SORT - CHECKED
void merge(int a[], int first, int mid, int last){
    int tmp[100000], index;
    int first1 = first, last1 = mid, first2 = mid+1, last2 = last;
    for (index = first1; (first1 <= last1) && (first2 <= last2) ; ++index)
    {
        if(a[first1] < a[first2]) {tmp[index] = a[first1]; ++first1;}
        else {tmp[index] = a[first2]; ++first2;}
    }
    for (; first1 <= last1; ++first1, ++index) tmp[index] = a[first1];
    for (; first2 <= last2; ++first2, ++index) tmp[index] = a[first2];
    for (index = first; index <= last; ++index) a[index] = tmp[index];
}
void MergeSort(int a[], int first, int last){
    if(first < last){
        int mid = (first + last)/2;
        MergeSort(a, first, mid);
        MergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}

//INSERTION SORT - CHECKED
void InsertionSort(int a[], int size){ //increasing order
    int k, pos, tmp;
    for (k = 1; k < size; k++)
    {
        tmp = a[k];
        pos = k;
        while ((pos > 0) && (a[pos-1] > tmp))
        {
            a[pos] = a[pos-1];
            pos = pos - 1;
        }
        a[pos] = tmp;
    }
}

//BUBBLE SORT - CHECKED
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void BubbleSort(int a[], int size){
    int sorted = 0; //early termination signal
    for (int i = 0; i < size-1; i++)
    {
        if(sorted == 0)
        {
            sorted = 1;
            for (int j = 0; j < size-i-1; j++)
            {
                if(a[j] < a[j+1]) // "<" => decreasing order; ">" => increasing order
                {
                    swap(&a[j], &a[j+1]);
                    sorted = 0;
                }
            }
        }
    }
}

//QUICK SORT (Code from slides, not checked)
//=> A - Pivot: First
int PartitionFirst(int A[], int left, int right){
    int i = left; int j = right + 1;
    int pivot = A[left];
    while (1)
    {
        i = i+1;
        while (i <= right && A[i] < pivot) i = i+1;
        j--;
        while (j >= left && pivot < A[j]) j = j-1;
        if (i >= j) break;
        swap(&A[i], &A[left]);
    }
    swap(&A[j], &A[left]);
    return j;
}
//=> - Pivot: Middle
int PartitionMid(int A[], int left, int right){
    int pivot = A[(left + right)/2];    
    while (left < right)
    {
        while (A[left] < pivot) left++;
        while (A[right] > pivot) right--;
        if (left < right){
            swap(&A[left], &A[right]);
            left++; right++;    
        }
    }
    return right;
}
//=> C - Pivot: Last
int PartitionLast(int A[], int left, int right){
    int pivot = A[right]; int j = left - 1;
    for (int i = left; i < right; i++){
        if (pivot >= A[i]){
            j = j + 1;
            swap(&A[i], &A[j]);
        }
    }
    A[right] = A[j + 1];
    A[j + 1] = pivot;
    return (j+1);
}

void QuickSort(int A[], int left, int right){
    int indexPivot;
    if (left < right){
        indexPivot = //<Partition Function of Choice>
        QuickSort(A, left, indexPivot-1);
        QuickSort(A, indexPivot+1, right);
    }
}

//HEAP SORT: See heapsort.c
