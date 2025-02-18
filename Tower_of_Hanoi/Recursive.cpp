#include <iostream>
using namespace std;

#define SIZE 10

int top = -1;
struct Stack
{
    int stack[SIZE];

    int _size()
    {
        return top+1;
    }

    bool isFull()
    {
        return top==SIZE-1;
    }

    // Function to push a value onto the stack
    void push()
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            int x;
            cout<<"Enter value to push: ";
            cin>>x;
            top=top+1;
            stack[top]=x;
            cout<<"Pushed Value: "<<stack[top]<< endl;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        if(top==-1)
        return true;
        return false;
    }

    // Function to pop a value from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            cout << "Popped value: " << stack[top] << endl;
            top--;
        }
    }
};

void tower(int n,char s,char h,char d)
{
    if (n == 0)
        return;
    tower(n-1,s,d,h);

    cout<<"Move disk "<<n<<" from "<<s<<" to "<<d<< endl;
    tower(n-1,h,s,d);
    return;
}


int main()
{
    int n;
    char s,h,d;

    cout<<"Enter the number of disks: ";
    cin>>n;
    cout<<"Enter the name of the source rod: ";
    cin>>s;
    cout<<"Enter the name of the helper rod: ";
    cin>>h;
    cout<<"Enter the name of the destination rod: ";
    cin>>d;

    tower(n,s,h,d);
    return 0;
}
