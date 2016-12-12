#include <iostream>
#include <cstdlib> 
#include <time.h>

using namespace std;

int main() 
{
    int guess_num, secret_num;
    
    srand(time(NULL));
    
    secret_num = rand() % 10 + 1;
    
    cout << "Guess the secret number(1 to 10)\n";
    cin >> guess_num;
    
    if(guess_num == secret_num)
        cout << "Bingo you nailed it!!!\n";
    else if(guess_num < secret_num)
        cout << "Oops! Little ahead!\n";
    else
        cout << "Oops! Little behind!\n";
        
    return 0;
}
