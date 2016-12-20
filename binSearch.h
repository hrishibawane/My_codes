#ifndef BINSEARCH_H_INCLUDED
#define BINSEARCH_H_INCLUDED

int binarySearch(int a[], int low, int high, int num)
{
    int mid = (low + high)/2;
    if(low > high)
        return -1;
    if(num == a[mid])
        return mid;
    else if(num < a[mid])
        return binarySearch(a, low, mid-1, num);
    else
        return binarySearch(a, mid+1, high, num);
}

#endif // BINSEARCH_H_INCLUDED
