#include<iostream>
using namespace std;

/* time cost: O(n)
   space cost: O(1)
shortcoming: will change the array
*/

bool get_duplicate(int *array, int length, int *num)
{
    if (array==nullptr || length<=0)
    {
        return false;
    }

    for(int i=0; i<length; i++)
    {
        if (array[i]<0 || array[i]>=length)
            return false;
    }

    for(int i=0; i<length; i++)
    {
       while(i!=array[i])
       {

        if (array[i] == array[array[i]])
        {
            *num = array[i];
            return true;
        }

        int tmp = array[i];
        array[i] = array[tmp];
        array[ tmp ] = tmp;
       }
    }
    return false;
}

void test_1()
{

    int array[] = {0, 1, 2, 3, 3};

    int num;
    
    bool result = get_duplicate(array, 5, &num);
    
    if (result) cout<<num<<endl;
    else cout<<"erro"<<endl;
    
}


//////////////////////////////////////////////////////////////////////////////////////

/**
time cost: O(nlogn)
space cost: O(1)

advantages: will not modify the array
shortcoming: time cost many;
*/

int get_count(const int *array, int length, int start, int end)
{
   
   int count = 0;
   if (array == nullptr || length<0)
      return 0;
   for(int i=0; i<length; ++i)
   {
    if ((start<=array[i]) && (array[i]<=end))
        count ++;
   }

   return count;
}
bool get_duplicate2 (const int * array, int length, int *num)
{
    if (array == nullptr|| length<=0)
    {
        return false;
    }

    for(int i=0; i<length; i++)
    {
        if (array[i]<0|| array[i]>= length)
            return false;
    }
    
    int start = 0;
    int end = length -1; // length
    int count =0 ;
    while(start<=end)
    {
        int mid = (end + start)/2;
        // int mid = ((end-start)>>1) + start;

        
        count = get_count(array, length, start, mid);
        cout<<"start: "<<start<<" |  end: "<<end<<endl;
        cout<<"mid: "<<mid<<endl;
        cout<<"count: "<<count<<endl;
        cout<<"*****"<<endl;
        if (end == start)
        {
             if (count > 1) 
            {
                *num = start;
                return true;
            }
            else break;
        }
        // if (count)
        if (count > (mid-start + 1))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
        
    }
    return false;
}

void test_2()
{
   int array[] = {0, 3, 1, 3};
   int num;
   bool result = get_duplicate2(array, 4, &num) ;

   if (result) cout<<num<<endl;
   else cout<<"no duplicate num"<<endl;

}
int main()
{
    // test_1();
    test_2();

}