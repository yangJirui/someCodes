#include<iostream>


using namespace std;


struct Node
{
    int x;
    Node* next;
    Node() = default;
    Node(int data): x(data), next(nullptr){}
};

Node * get_list_by_cin()
{
    int data;
    Node* head = nullptr;
    if(cin>>data)
        head = new Node(data);
    else
        return nullptr;
    Node* p= head;
    while(cin>>data)
    {
        p->next = new Node(data);
        p = p->next;
    }
    return head;
}
void print_Kth_to_tail(Node* head, int k)
{

  if (head==nullptr)
    return ;
  int length = 0;

  Node * p = head;
  while(p!=nullptr)
  {
    length++;
    p = p->next;
  }

  if(length<k)
    return ;

  int index = length -k;
  // cout<<index<<endl;
  p = head;
  for(int i = 0; i<index; i++)
  {
    p = p->next;
  }
  cout<<p->x<<endl;
}
void print_Kth_to_tail_2(Node* head, int k)
{
    if(head == nullptr||k<=0)
        return ;
    Node* pf = head;
    Node* pb = head;

    for(int i=0; i<k-1; i++)
      {
        pf = pf->next;
        if (pf== nullptr)
            return ;
      }

    while(pf->next!=nullptr)
    {
        pb = pb->next;
        pf = pf->next;
    }
    cout<<pb->x<<endl;

}
int main()
{   Node* head = get_list_by_cin();
    print_Kth_to_tail_2(head, 1);
}