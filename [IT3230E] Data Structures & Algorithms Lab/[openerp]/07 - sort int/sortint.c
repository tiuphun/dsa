/* DONE
Given a sequence of integers a1, a2, ..., an. Sort the sequence in a non-decreasing order.

Input
Line 1: contains an integer n (1 <= n <= 1000000)
Line 2: a1, a2, ..., an. (0 <= ai <= 100000)
Output
Write the sorted sequence, elements are separated by a SPACE character.

Example
Input
4
1 3 4 2
Output
1 2 3 4 */
#include <stdio.h>
int n; 
int a[100000];
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
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void selectionSort(int a[], int n){
    int i, j, index_min;
    for (i = 0; i < n-1; i++){
        index_min = i;
        for (j = i+1; j < n; j++)
        if (a[j] < a[index_min]) index_min = j;
        swap(&a[i], &a[index_min]);
    } 
}
void insertionSort(int a[], int size){
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
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
