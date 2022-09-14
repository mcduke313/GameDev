// Week2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void function1(int x, int y)
{
    for (int i = 0 ; i<= 1000 ; i++)
    {
        if ( i % x == 0 || i % y == 0) //didn't know if it should be divisible by both or either
        {
            cout << i;
        }
    }
}
void function2(string str1)
{
    string str2;
    for (int i = str1.length() - 1; i >= 0 ; i--)
    {
        str2 += str1.at(i);
    }
    cout << str2 << endl;
}
void function3(string str)
{

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str.at(i) == 'a'|| str.at(i) == 'A' || str.at(i) == 'e' || str.at(i) == 'E' || str.at(i) == 'i' || str.at(i) == 'I' || str.at(i) == 'o' || str.at(i) == 'O' || str.at(i) == 'u' || str.at(i) == 'U')
        {
            str.erase(str.begin()+i);
        }
    }
    cout << str << endl;
}

int main()
{
    function1(2,5);
    function2("Hello World");
    function3("The Cake is a Lie");
}

