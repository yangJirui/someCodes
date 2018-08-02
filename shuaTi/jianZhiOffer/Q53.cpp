#include<iostream>
using namespace std;
int get_count(int* array, int num, int length)
{
   
   int count = 0;

   int st = 0;
   int end = length-1;
   
   int left = 0;
   int right = 0;
   while(st<=end)
   {
    cout<<"st "<<st<<" | end "<<end<<endl;
    int mid = (st+end)>>1;
    if(array[mid]==num)
    {
        if(mid-1>=st&&array[mid-1]!=num)
        {
           left = mid;
        }
        else
        {
            st = st;
            end = mid-1;
        }
        if(mid+1<=end&&array[mid+1]!=num)
            right = mid;
        else
        {
            st = mid+1;
            end = end;
        }
    }
    if(array[mid]>num)
    {
        st = st;
        end = mid-1;
    }
    else
    {
        st = mid+1;
        end = end;
    }
    cout<<"st "<<st<<" | end "<<end<<endl;
    cout<<"left"<<left<<" | right"<<right<<endl;
   }
   
   return right-left+1;
}

int main()
{
    int array[] = {1, 2, 3, 3, 3, 3, 4, 5};

    cout<<get_count(array, 3, 7)<<endl;
}