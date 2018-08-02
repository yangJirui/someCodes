#include<iostream>
using namespace std;

int get_subarray(int* array, int length)
{
    if(array == nullptr|| length<=0)
        return nullptr;
    
    int sum=0;
    int max_sum = 0;
    for(int i=0; i<length; i++)
    {   

        if(sum + array[i]< array[i])
        {
            sum = array[i];
        }
        else
            {
                sum += array[i];
            }

       
       if(sum > max_sum)
          {
            max_sum = sum;

          }
    }

    return max_sum;
}


int get_max_subsum(int* array, int N)
{
    if(array==nullptr|| N<=0)
        return -1;

    int max_sum[N] ;
    for (int i=0；i<N; i++)
        max_sum[i]= 0;

    max_sum[0] = array[0];
    int maximum_sum = max_sum[0];

    for(int i =1; i < N; i++)
    {
        if(max_sum[i-1]<0)
            max_sum[i] = array[i];
        else
            max_sum[i] = max_sum[i-1] + array[i];

        if (maximum_sum<max_sum[i])
            maximum_sum = max_sum[i];
    }

    return maximum_sum;
}