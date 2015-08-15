enum TYPES{ CHAR, INT};
enum OP{ PUSH, POP};
struct element
{
    int tag;
    union{
        char c;
        int i;
        }e;
};

struct xfix
{
    element e[50];
    int s;

    xfix(){s = 0;};
};

void strrev(string a,int s, int i=0)
{
    while(i < s)
    {
        a[i] = a[i]^a[s-i-1];
        a[s-i-1] = a[i]^a[s-i-1];
        a[i] = a[i]^a[s-i-1];
    }
}
void stringtoxfix(string in,xfix &x)
{
    int temp=0;
    int i=0;
    in = in+"#";
    while(in[i]!='#')
    {
        switch(in[i])
        {
            case '/':
            case '*':
            case '-':
            case '+':
            case ')':
            case '(': x.s++; x.e[x.s-1].e.c = in[i];x.e[x.s-1].tag = CHAR;break;
            case '#':break;
            default:
                    while(in[i]!=')'&&in[i]!='/'&&in[i]!='*'&&in[i]!='-'&&in[i]!='+'&&in[i]!='('&&in[i]!='#')
                    {
                        temp = temp*10 + in[i] - 48;
                        i++;
                    }
                    i--;
                    x.s++; x.e[x.s-1].e.i = temp;x.e[x.s-1].tag = INT;
                    temp = 0;
                    break;
        }
        i++;

    }
}

void printxfix(xfix x)
{
    for(int i=0;i<x.s;i++)
    {
        if(x.e[i].tag == INT)
        {
            cout<<x.e[i].e.i<<" ";
        }
        else
            cout<<x.e[i].e.c<<" ";
    }
}

int checkprecedence(char a, char b)
{
    ///returns  1 for pop 0 for push
    if(!(a^b)) ///if same
    {
        return 1;
    }
    else if(a == '-')
    {
        if( b == '*' || b == '/')
            return 0;
        else if(b == '+')
            return 1;
    }
    else if(a == '+')
    {
        if( b == '*' || b == '/')
            return 0;
        else if(b == '-')
            return 1;
    }
    else
        return 0;

}

char open[] = {'(','[','{'};
char close[] = {')',']','}'};
int getnumber( char a )
{
    switch(a)
    {
        case '(':
        case ')':return 0;
        case '[':
        case ']':return 1;
        case '{':
        case '}':return 2;
        default: return 7;
    }
}
int balanced(xfix x)
{
    //cout<<".1.";
    cStack oS;
    iStack iS;
    //cout<<".2.";
    int level = 0;
    int flag = 0;

    //cout<<x.s;
    for(int i = 0;i<x.s;i++ )
    {
        if(x.e[i].tag == INT)
        {
            iS.push(x.e[i].e.i);
            //cout<<"bbbbb";
        }
        else   ///operator
        {
            if(getnumber(x.e[i].e.c)!=7)   ///brackets encountered
            {
                //cout<<"aaaa";

                if(x.e[i].e.c == open[getnumber(x.e[i].e.c)])
                {
                    oS.push(x.e[i].e.c);
                    level++;
                }
                else if( x.e[i].e.c == close[getnumber(x.e[i].e.c)])
                {
                    level--;
                    oS.top(flag);
                    while(flag)
                    {
                        if(level == 0)
                            break;
                        else if(oS.top(flag) == close[getnumber(x.e[i].e.c)])
                            level--;
                        else if(oS.top(flag) == open[getnumber(x.e[i].e.c)])
                            {level++;break;}
                        /*if(flag)
                        {
                                return 0;
                        }*/
                        oS.pop(flag);
                        //cout<<level<<endl;
                    }
                    //if(level)
                      //  return 1;
                }
            }
            else
            {   oS.top(flag);
                if(!flag)
                {
                    if(checkprecedence(oS.top(flag),x.e[i].e.c == 0))
                        oS.push(x.e[i].e.c);
                    else
                    {
                        oS.pop(flag);
                        oS.push(x.e[i].e.c);
                    }
                }
                else
                    oS.push(x.e[i].e.c);
            }
        }
    }
    if(level)
        return 0;
    return 1;
}
