struct iStack
{
        int *e;
        int t;
        int ss;

        //functions

        iStack(){t = -1;ss = 50;e = new int [50];};
        iStack(int a){t = -1;ss = a;e = new int [a];};
        void push(int a);
        int pop(int &flag);
        int top(int &flag);
        int isEmpty(){if(t == -1)return 1;else return 0;}
        ~iStack(){delete[] e;};

};

void iStack::push(int a)
{
    if(t == ss)
    {
        cout<<"\nOverflow, can't push\n";
        return;
    }
    t++;
    e[t] = a;
}

int iStack::pop(int &flag)
{
    if(t <0)
    {
        int flag = 1;
        return 0;
    }
    else
        return e[t--];
}


int iStack::top(int &flag)
{
    if(t <0)
    {
        flag = 1;
        return 0;
    }
    else
        return e[t];
}


struct cStack
{
        char *e;
        int t;
        int ss;

        //functions

        cStack(){t = -1;ss = 50;e = new char [50];};
        cStack(char a){t = -1;ss = a;e = new char [a];};
        void push(char a);
        char pop(int &flag);
        char top(int &flag);
        int isEmpty(){if(t == -1)return 1;else return 0;}
        ~cStack(){delete[] e;};

};

void cStack::push(char a)
{
    if(t == ss)
    {
        cout<<"\nOverflow, can't push\n";
        return;
    }
    t++;
    e[t] = a;
}

char cStack::pop(int &flag)
{
    if(t <0)
    {
        flag = 1;
        return 0;
    }
    else
        return e[t--];
}


char cStack::top(int &flag)
{
    if(t <0)
    {
        flag = 1;
        return 0;
    }
    else
        return e[t];
}
