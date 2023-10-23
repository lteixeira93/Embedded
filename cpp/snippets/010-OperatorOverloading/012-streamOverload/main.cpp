#include <iostream>
#include "MyString.hpp"

using namespace std;

int main() {
    
    MyString larry {"Larry"};
    MyString moe {"Moe"};
    MyString curly;
    
    cout << "Enter the third stooge's first name: ";
    cin >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    return 0;
}

