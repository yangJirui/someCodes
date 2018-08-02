#include<iostream>
using namespace std;

struct Node
{
    int x;
    Node* next;
    Node() = default;
    Node(int data): x(data), next(nullptr) {}

};

Node * get_list(bool cycle)
{
    Node* head = new Node(1);
    
    Node* p = head;
    Node* pend = nullptr;
    Node* p3 = nullptr;
    for (int i = 2; i<=6; i++)
    {
        p->next= new Node(i);
        if (i==3)
            p3 = p->next;
        if(i==6)
            pend = p->next;
        p = p->next;
    }

    if (cycle)
    {
        // pend->next = p3;
        // return head;

        Node* node1 = new Node(1);
        Node* node2 = new Node(2);
        Node* node3 = new Node(3);
        Node* node4 = new Node(4);
        Node* node5 = new Node(5);
        Node* node6 = new Node(6);

        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node4;
        return node1;
    }
    else return head;
}
Node* print_list(Node* head)
{
    Node* p = head;
    int count =0;
    while(p!=nullptr)
    {
        cout<<p->x<<endl;
        p = p->next;
        count++;
        if (count == 7)
            break;
    }
    cout<<"**"<<endl;
}

Node* find_cycle_in(Node* head)
{
    if (head==nullptr)
        return nullptr;

    Node * pfast = head;
    Node* pslow = head;

    while(1)
    {
        if(pfast==nullptr||pfast->next==nullptr)
            {
                cout<<"no cycle in the list"<<endl;
                return nullptr;
            }
        else
        {
            pfast = pfast->next->next;
            
            if(pfast==pslow)
                return pfast;
            pslow = pslow->next;
            // cout<<"+++:"<<pfast->x<<endl;
            // cout<<"+++:"<<pslow->x<<endl;
        }
    }
}

int get_cycle_len(Node* in_node)
{
    int count = 0;
    Node* p = in_node->next;
    while(p!=in_node)
    {
        count ++;
        p = p->next;
    }
    return count+1;
}

Node* find_cycle_begin(Node*head)
{
    if(head==nullptr)
        return nullptr;
    Node* node_in = find_cycle_in(head);
    if (node_in==nullptr) return nullptr;

    int cycle_len = get_cycle_len(node_in);
    cout<<"the len is :"<<cycle_len<<endl;
    Node* pbehind = head;
    Node* pfront = head;
    for(int i =0; i< cycle_len; i++)
        pfront = pfront->next;
    // cout<<pfront->x<<endl;
    while(pfront!= pbehind)
    {
        pfront = pfront->next;
        pbehind = pbehind->next;
    }

    return pbehind;

}
int main()
{
    Node* head = get_list(true);
    cout<<"create_over"<<endl;
    print_list(head);
    Node* in_node = find_cycle_begin(head);

    cout<<in_node->x<<endl;
}