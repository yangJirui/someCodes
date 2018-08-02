#include<iostream>
#include<stack>

using namespace std;

void ten_to_binary(int num)
{ 

    stack<int> result_stack;
    

    while(num>0)
    {
        int yushu = num % 2;

        num = num /2;

        result_stack.push(yushu);
    }
    
    while(!result_stack.empty())
    {
        cout<<result_stack.top();
        result_stack.pop();
    }
    cout<<endl;
}


int main()
{
    ten_to_binary(127);
}