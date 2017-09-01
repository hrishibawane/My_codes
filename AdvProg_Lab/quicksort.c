#include <stdio.h>
#include <stdlib.h>

//***********************MERGESORT****************************
void merge(int left[], int leftCount, int right[], int rightCount, int A[])
{
    int i=0, j=0, k=0;
    while(i<leftCount && j<rightCount)
    {
        //choose element from left or right which is lesser
        if(left[i] < right[j])
            A[k++] = left[i++];
        else
            A[k++] = right[j++];
    }
    //filling of remaining elements of left or right
    while(i<leftCount)
        A[k++] = left[i++];

    while(j<rightCount)
        A[k++] = right[j++];
}

void mergeSort(int A[], int n)
{
    //exit condition
    if(n==1) return;

    int mid = n/2;
    int left[mid], right[n-mid];

    for(int i=0; i<mid; i++)
        left[i] = A[i];

    for(int i=mid; i<n; i++)
        right[i-mid] = A[i];

    //recursively reduce the left & right arrays till 1 element is left
    mergeSort(left, mid);
    mergeSort(right, n-mid);
    merge(left, mid, right, n-mid, A);
}

//*********************QUICKSORT*********************************
int partition(int a[], int beg, int end)
{
    int pivot = a[end], pIndex = beg, temp;
    for(int i=beg; i<end; i++)
    {
        if(a[i]<=pivot)
        {
            temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    temp = a[pIndex];
    a[pIndex] = a[end];
    a[end] = temp;
    return pIndex;
}

void quickSort(int a[], int beg, int end)
{
    if(beg<end)
    {
        int pIndex = partition(a, beg, end);
        quickSort(a, beg, pIndex-1);
        quickSort(a, pIndex+1, end);
    }
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements\n");
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int ch;
    while(1)
    {
        printf("\n1. Merge Sort\n2. Quick Sort\n3. End\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: mergeSort(a, n);
                break;
            case 2: quickSort(a, 0, n-1);
                break;
            case 3: return 0;
        }
        for(int i=0; i<n; i++)
            printf("%d ", a[i]);
    }
}
