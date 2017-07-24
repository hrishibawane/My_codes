#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Book
{
    char *name, *author, *publisher;
    int stock;
    double price;
    static int valid_trans;
public:
    Book();
    void Accept();
    void Display();
    int Search(char[]);
    friend void disp_All(Book[], int);
    void Update();
    void Purchase(int);
    static void Transactions(){cout << "\nT" << valid_trans;}
};
int Book::valid_trans = 0;
Book::Book()
{
    name = new char[15];
    author = new char[15];
    publisher = new char[15];
    stock = 0;
    price = 0.00;
}
void Book::Accept()
{
    cout << "\nEnter Book Data:";
    cout << "\nBook Name: "; cin >> name;
    cout << "\nAuthor: "; cin >> author;
    cout << "\nPublisher: "; cin >> publisher;
    cout << "\nPrice: "; cin >> price;
    cout << "\nStock: "; cin >> stock;
}
void Book::Display()
{
    cout << "\nBook Data:";
    cout << "\nBook Name: " << name;
    cout << "\nAuthor: " << author;
    cout << "\nPublisher: " << publisher;
    cout << "\nPrice: " << price;
    cout << "\nStock: " << stock;
}
int Book::Search(char s[])
{
    return (strcasecmp(name, s)==0) ? 1 : 0;
}
void disp_All(Book b[20], int n)
{
    cout << "\nBook data:";
    cout << "\nSr.No.\tBookName\tAuthor\tPublisher\tPrice\tStock";
    for(int i=0; i<n; i++)
        cout << "\n" << i+1 << setw(10) << b[i].name << setw(10) << b[i].author << setw(10) << b[i].publisher << setw(10) << b[i].price << setw(10) << b[i].stock;
}
void Book::Update()
{
    int ch;
    cout << "\nUpdate:\n1. Stock\n2. Price";
    cin >> ch;
    if(ch==1)
    {
        cout << "Enter new stock" << endl;
        cin >> ch;
        stock += ch;
    }
    else
    {
        cout << "Enter new Price";
        cin >> price;
    }
}
void Book::Purchase(int n)
{
    if(n<=stock)
    {
        cout << "\nTotal Price of Books: " << n*price;
        stock -= n;
        valid_trans++;
    }
    else cout << "\nBook out of stock!!!";
}

int main()
{
    int n;
    Book b[25];
    char name[20];
    cout << "\nAccept Book Data for N books: ";
    cin >> n;
    for(int i=0; i<n; i++)
        b[i].Accept();
    int choice, i;
    while(1)
    {
        cout << "\n1. Add new book\n2. Display all books\n3. Search\n4. Update\n5. Purchase\n6. Valid transactions\n7. End\n";
        cin >> choice;
        switch(choice)
        {
            case 1: cout << "Add New Book: ";
            b[n++].Accept();
            break;

            case 2: disp_All(b, n);
            break;

            case 3: cout << "Enter book name to search: ";
            cin >> name;
            for(i=0; i<n; i++)
                if(b[i].Search(name))
                {
                    b[i].Display();
                    break;
                }
            if(i==n) cout << "\nBook is not available";
            break;

            case 4: cout << "\nEnter book name to update: ";
            cin >> name;
            for(i=0; i<n; i++)
                if(b[i].Search(name))
                {
                    b[i].Display();
                    b[i].Update();
                    break;
                }
            if(i==n) cout << "\nBook is not available";
            break;

            case 5: cout << "\nEnter book name to purchase ";
            cin >> name;
            cout << "\nEnter no. of books to be purchased: ";
            int no;
            cin >> no;
            for(i=0; i<n; i++)
                if(b[i].Search(name))
                {
                    b[i].Display();
                    b[i].Purchase(no);
                    break;
                }
            if(i==n) cout << "\nBook is not available";
            break;

            case 6: Book::Transactions();
            break;

            case 7: exit(0);
            default: cout << "Wrong choice\n";
        }
    }
}