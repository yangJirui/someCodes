#include<iostream>
#include<vector>

using namespace std;

struct Node
{
   int x;
   int y;
   Node() = default;
   Node(int x, int y): x(x), y(y) {}
};


Node pop_stack(vector<Node> &stack)
{   
    if (stack.empty())
    {
        cout<<"there are no element in the stack, erro"<<endl;
        return Node(-1, -1);
    }
    Node stack_top = *(stack.end()-1);

    stack.erase(stack.end()-1);
    
    return stack_top;
}

void push_stack(vector<Node> &stack, Node *new_node)
{
    stack.push_back(*new_node);
    delete new_node;
    
    return ;
}

void print_stack(const vector<Node> &stack)
{
    for(auto node: stack)
    {
        cout<<node.x<<" | "<<node.y<<endl;
    }
    cout<<"_____________"<<endl;
}
int main()
{
    vector<Node> stack;
    push_stack(stack, new Node(1, 1));
    push_stack(stack, new Node(2, 2));
    push_stack(stack, new Node(3, 3));
    print_stack(stack);

    Node ele = pop_stack(stack);

    cout<<"ele data is ("<<ele.x<<" | "<<ele.y<<")"<<endl;

    print_stack(stack);

}

