//A compilation of all sorting function based on sorting techniques.
#include <stdio.h>
#include <stdlib.h> //This library contains all the sorting functions already.
#define SIZE 100
int a[SIZE];

//SELECTION SORT
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

//MERGE SORT
void merge(int a[], int first, int middle, int last){
    int tmp[SIZE], index;
    int first1 = first, last1 = middle, first2 = mid+1, last2 = last;
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
        int middle = (first + last)/2;
        MergeSort(a, first, middle);
        MergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}

//INSERTION SORT
void InsertionSort(int a[], int size){
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

//BUBBLE SORT
void BubbleSort(int a[], int size){
    int sorted = 0; //early termination signal
    for (int i = 0; i < n-1; i++)
    {
        if(sorted == 0){
            sorted = 1;
            for (int j = 0; j < n-i-1; j++)
            {
                if(a[j] < a[j+1]){
                    swap(&a[j], &a[j+1]);
                    sorted = 0;
                }
            }
            
        }
    }
}

//QUICK SORT
void QuickSort(int a[], int size){

}