/* REVISITED (Binary Search) DONE
    Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. 
    Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

    Dữ liệu
    Dòng 1: ghi n và M (1 <= n, M <= 1000000)
    Dòng 2: ghi a1, a2, ..., an
    Kết quả
    Ghi ra giá trị Q

    Ví dụ
    Dữ liệu
    5 6
    5 2 1 4 3
    Kết quả
    2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[1000000], n, M, Q;
int BinarySearch(int a[], int LeftIndex, int RightIndex, int B){
    if(LeftIndex > RightIndex) return -1;
    if(LeftIndex == RightIndex){
        if(a[LeftIndex] == B) return LeftIndex;
        else return -1; 
    }
    int middle = (LeftIndex + RightIndex)/2;
    if (a[middle] == B) return middle;
    if (a[middle] > B) return BinarySearch(a, LeftIndex, middle-1, B);
    if (a[middle] < B) return BinarySearch(a, middle+1, RightIndex, B);
    return -1;
}
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
int main(int argc, char const *argv[])
{
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    MergeSort(a, 0, n-1);
    //for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    for (int i = 0; i < n-2; i++) 
    {
        int index = BinarySearch(a, i+1, n-1, M - a[i]); //(i+1) since we're searching for a[j] w/ j > i
        //printf("i = %d, a[i] = %d, index = %d\n",i,a[i],index);
        if (index > 0) Q++;
    }
    printf("%d\n", Q);
    return 0;
}
