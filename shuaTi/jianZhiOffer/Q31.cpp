#include<iostream>
#include<stack>

using namespace std;

bool is_right(int * in_array, int *out_array, int N)
{
   stack<int> help_stack;

   if(in_array==nullptr|| out_array==nullptr|| N<=0)
    return false;

   int index = 0;
   for(int i=0;; )
   {
    if(index>=N)
        break;
    if (help_stack.empty()|| help_stack.top()!=out_array[index])
        {
            if(i>=N) break;
            help_stack.push(in_array[i]);
            i++;
        }
    else
    {
        index ++;
        help_stack.pop();
    }
   }
   if(index >=N)
     return true;
   else return false;
}
int main()
{   
    int in_array[] ={1};
    int out_array[] = {1};
    cout<<is_right(in_array, out_array, 1)<<endl;
}