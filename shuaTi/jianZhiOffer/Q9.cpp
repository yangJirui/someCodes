#include<iostream>
#include<stack>

using namespace std;


template<typename T> class Queue
{
    public:
        Queue(void);
        ~Queue(void);

        void appendTail(const T& node);
        T deleteHead();
    private:
        stack<T> stack1;
        stack<T> stack2;
};


template<typename T> void Queue::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T Queue:: deleteHead()
{
    while(!stack1.empty())
    {
        T& top = stack1.top();
        stack1.pop();
        stack2.push(top);
    }
    if(stack2.empty())
        throw new exception("queue is empty");
    T head = stack2.top();
    stack2.pop();
    return head;
}