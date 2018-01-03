#include <iostream>
using namespace std;

template <class T>
class Stack
{
	public:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head;
	Stack(){head=NULL;}
	void push(int x);
	void pop();
	T top();
	bool isempty();
	void display();
};

template <class T> void Stack<T> :: push(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = (head==NULL) ? NULL : head;
	head = temp;
}

template <class T> void Stack<T> :: pop()
{
	Node* temp = head;
	head = head->next;
	delete temp;
}

template <class T> T Stack<T> :: top() {return head->data;}

template <class T> bool Stack<T> :: isempty() {return (head==NULL);}

template <class T> void Stack<T> :: display()
{
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

bool isOperator(char c)
{
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int precede(char c)
{
	if(c=='^') return 3;
	if(c=='*' || c=='/') return 2;
	if(c=='+' || c=='-') return 1;
	return 0;
}

string infixToPost(string str)
{
	int len = str.length();
	Stack<char> s;
	string res = "";

	for(int i=0; i<len; i++)
	{
		if(!isOperator(str[i]) && str[i]!='(' && str[i]!=')') res+=str[i];
		else if(isOperator(str[i]))
		{
			while(!s.isempty() && s.top()!='(' && precede(s.top()) > precede(str[i]))
				res += s.top(), s.pop();

			s.push(str[i]);
		}
		else if(str[i]=='(') s.push(str[i]);
		else if(str[i]==')')
		{
            while(!s.isempty() && s.top()!='(')
                res += s.top(), s.pop();

            s.pop();
		}
	}

	while(!s.isempty())
		res+=s.top(), s.pop();

	return res;
}

int main()
{
	string str;
	cin>>str;
	cout<<infixToPost(str)<<endl;
}





