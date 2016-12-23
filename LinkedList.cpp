#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    head = NULL;                            //List is Empty
    int n;
    cout << "How many numbers?\n";
    cin >> n;

    int num, choice, position;
    cout << "\nMENU\n1. Insert at beginning\n2. Insert at end\n3. Insert at nth position\n";
    cin >> choice;

    switch(choice)
    {
        case 1:
        for(int i = 0; i < n; i++)
        {
            cout << "Enter number to insert:\n";
            cin >> num;
            insertFront(num);                      //Data will be inserted from beginning
            print();
        }
        break;
        case 2:
        for(int i = 1; i <= n; i++)
        {
            cout << "Enter number to insert:\n";
            cin >> num;
            insertBack(num, i);                   //Data will be inserted at end wrt position during iteration of loop
            print();
        }
        break;
        case 3:
        for(int i = 0; i < n; i++)
        {
            cout << "Enter number to insert & position to be inserted at:\n";
            cin >> num >> position;
            insertBack(num, position);
            print();
        }
    }
}
