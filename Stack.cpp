#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* top;

class Stack
{
public:
	Stack(){top = NULL;}
	Node* Push(Node* top, int num)
	{
		Node* temp = new Node();
		temp->data = num;
		temp->next = top;
		top = temp;
		return top;
	}
	Node* Pop(Node* top)
	{
		Node* temp = top;
		cout << "\nElement Popped: " << top->data << "\n";
		top = top->next;
		delete temp;
		return top;
	}
	void Top(Node* top) 
	{
		(top == NULL) ? cout << "\nStack is Empty\n" : cout << top->data << "\n";
	}
	void IsEmpty(Node* top)
	{
		(top == NULL) ? cout << "\nStack is Empty\n" : cout << "\nStack is not Empty\n";
	}

	void Print(Node* top)
	{
		Node* temp = top;
		cout << "\nStack: ";
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main()
{
	int choice;
	cout << "\nStack Operations\n1. Push element in the stack\n2. Pop element from stack\n3. Get topmost element from stack\n4. Check whether stack is empty\n5.Traverse the stack\n6.Quit\n";
	
	Stack s;

	while(1)
	{
		cout << "Select an option: ";
		cin >> choice;
		switch(choice)
		{
			case 1: cout << "\nEnter element to Push: ";
				int num;
				cin >> num;
				top = s.Push(top, num);
				break;

			case 2: top = s.Pop(top); break;

			case 3: s.Top(top); break;

			case 4: s.IsEmpty(top); break;

			case 5: s.Print(top); break;

			default: exit(1); break;
		}
	}

}