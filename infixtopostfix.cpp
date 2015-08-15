#include<iostream>
using namespace std;
#include "stacks.cpp"
#include "xfix.h"

int infixtopostfix(xfix ix, xfix &px)
{
    cStack oS;
    int flag = 0;
    px.s = 0;
    for(int i=0;i<ix.s;i++)
    {
        if(ix.e[i].tag = INT)
        {
            px.e[px.s].tag = INT;
            px.e[px.s++].e.i = ix.e[i].e.i;
        }
        else   ///operator
        {
            if(oS.isEmpty())
            {
                oS.push(ix.e[i].e.c);
            }
            else if(ix.e[i].e.c == '(')
            {
                oS.push(ix.e[i].e.c);
            }
            else if(ix.e[i].e.c == ')')
            {
                while(oS.top(flag) != '(')
                {
                    px.e[px.s].tag = CHAR;
                    px.e[px.s++].e.c=oS.pop(flag);
                }
                oS.pop(flag);   ///get rid of the '('
            }
            else if(checkprecedence(oS.top(flag),ix.e[i].e.c) == POP)
            {
                while((checkprecedence(oS.top(flag),ix.e[i].e.c) == POP)&&!flag&&oS.top(flag)!='(')
                {
                    px.e[px.s].tag = CHAR;
                    px.e[px.s++].e.c = oS.pop(flag);
                }
                oS.push(ix.e[i].e.c);
            }
            else    ///PUSH
            {
                oS.push(ix.e[i].e.c);
            }
        }
    }
    if(!oS.isEmpty())
    {
        px.e[px.s++].e.c = oS.pop(flag);
    }
}

int main()
{
    string s;
    xfix in, px;
    cout<<"Enter the infix expression : ";
    cin>>s;
    stringtoxfix(s,in);
    if(balanced(in))
    {
        infixtopostfix(in,px);
    }

    cout<<"\nThe infix is : ";
    printxfix(in);
    cout<<"\nThe postfix expression is : ";
    printxfix(px);
    return 0;
}
