#include<iostream>

using namespace std;


void quick_sort_recurrent(int *array, int st, int end)
{
    
    if (array == nullptr|| st >= end)
        return;
    int index = st;

    int split_data = array[index];
    // cout<<split_data<<endl;
    int small_index = st, large_index = end;

    while(small_index!=large_index && small_index<=end && large_index>=st)
    {
        if(array[large_index]>=split_data)
            large_index --;
        else
        {
            if(array[small_index]<=split_data)
                small_index++;
            else
            {
                int tmp = array[large_index];
                array[large_index] = array[small_index];
                array[small_index] = tmp;
                large_index --;
                small_index ++;
            }
        }
    }
    if(large_index == small_index)
    {
        array[index] = array[large_index];
        array[large_index] = split_data; 
    }
    for(int i=st; i<= end; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"****"<<endl;
    quick_sort_recurrent(array, st, large_index-1);
    quick_sort_recurrent(array, large_index+1, end);
}



void quick_sort(int *array, int st, int end)
{
   
   if(st>=end)
     return ;

   int left = st;
   int right = end;
   int compare_value = array[st];
   int count  = 0;
   while(left!=right)
   {  
    count++;
    if(count == 5)
        return;

    while(left<right&&array[right]>=compare_value)
        right--;

    while(left<right&&array[left]<=compare_value)
        left++;

    if(left<right)
        {
            int tmp = array[right];
            array[right] = array[left];
            array[left] = tmp;
        }
   }
   
   array[st] = array[left]; // left == right
   array[left] = compare_value;
   quick_sort(array, st, left-1);
   quick_sort(array, right+1, end);
}


void quick_sort_with_random(int *array, int st, int end)
{
    
    if(end<=st) return;    
    int choosed_index = rand()%(end-st) + st;

    int compare_value = array[choosed_index];
    
    array[choosed_index] = array[end];
    array[end] = compare_value;  //将这个需要比较的值放在最后面

    int small = st-1;

    for(int index=st; index<end; index++)
    {
        if(array[index]<compare_value)
        {
           small++;
           if(small<index)
           {
              int tmp = array[index];
              array[index] = array[small];
              array[small] = tmp;
          }
        }
    } 
    ++small;
    array[end] = array[small];
    array[small] = compare_value;//将最后一个数（被比较的数）放在中间

    quick_sort_with_random(array, st, small-1);
    quick_sort_with_random(array, small+1, end);
}
void test()
{
    int array[] = {5, 2, 1, 4, 3};
    int N = 5;
    quick_sort_with_random(array, 0, N-1);

    for(int i=0; i< N; i++)
    {
        cout<<array[i]<<endl;
    }
}

int main()
{
    test();
}