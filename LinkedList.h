#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

using namespace std;
struct Node
{
    int data;
    Node* link;
};
Node* head;
void insertFront(int num)
{
    Node* temp = new Node();
    temp->data = num;
    temp->link = head;
    head = temp;
}
void insertBack(int num, int n)
{
    Node* temp1 = new Node();

    temp1->data = num;
    temp1->link = NULL;
    if(n == 1)
    {
        temp1->link = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < n - 2; i++)
        temp2 = temp2->link;

    temp1->link = temp2->link;
    temp2->link = temp1;
}
void print()
{
    Node* temp = head;

    cout << "List: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << "\n";
}
#endif // LINKEDLIST_H_INCLUDED
