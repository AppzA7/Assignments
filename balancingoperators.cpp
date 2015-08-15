#include<iostream>
using namespace std;
#include"stacks.cpp"
#include"xfix.h"


int main()
{
    string a;
    again:
    cout<<"\nEnter infix : ";
    cin>>a;
    xfix x;
    stringtoxfix(a,x);
    if(balanced(x))
    {
        cout<<"\nThe expression is a balanced expression.\n";
    }
    else
        cout<<"\nThe expression is an unbalanced equation. \n";
    goto again;
    return 0;
}
