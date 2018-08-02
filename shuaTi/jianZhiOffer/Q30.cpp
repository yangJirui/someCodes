#include<iostream>
#include<stack>

using namespace std;

class Mystack
{
public:
    Mystack()= default;
    void push(int num);
    int pop();
    int min();
    stack<int> real_stack;
    stack<int> help_stack;
};

void Mystack::push(int num)
{
    real_stack.push(num);
    if(help_stack.empty()|| help_stack.top()>num)
            help_stack.push(num);
    else
        help_stack.push(help_stack.top());

}

int Mystack::pop()
{
    help_stack.pop()

    int num = real_stack.top()
    real_stack.pop()
    return num;
}

int min()
{
    if(help_stack.empty())
        return -1;
    else
        return help_stack.top();
}

void print_stack(Mystack* a)
{
    for(auto i: a->real_stack)
        cout<<i<<endl;
}
int main()
{
    Mystack * a = new Mystack();

    a->push(3);
    a->push(4);
    print_stack(a);
}