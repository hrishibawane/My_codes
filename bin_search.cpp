#include <iostream>
#include "binSearch.h"

using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of elements\n";
    cin >> n;

    int a[n];
    cout << "Enter elements in ascending order\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int num;
    cout << "Enter no. to search\n";
    cin >> num;

    int index = binarySearch(a, 0, n-1, num);

    (index != -1) ? cout << "Found " << num << " at index " << index : cout << num << " not found\n";
}
