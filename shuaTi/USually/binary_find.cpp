# include<iostream>
using namespace std;

int find_index(int *array, int data, int st, int end)
{

    if (array==nullptr)
        return -1;
   
    
     if(st>end)
        {cout<<"not find"<<endl;
         return -1;}
    int mid = (st+end)>>1;

    if(array[mid]==data)
        return mid;
    int index = -1;
    if (data>array[mid])
        index = find_index(array, data, mid+1, end);
    else
        index = find_index(array, data, st, mid-1);
    
    return index;
}

int find_index_loop(int*array, int data, int st, int end)
{
    if (array==nullptr)
        return -1;
    while(st<=end)
    {
        int mid = (st+end)>>1;

        if(array[mid]==data)
            return mid;

        if(array[mid]>data)
        {
            end = mid -1;
        }
        else
            st = mid + 1;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5};

    cout<<find_index(array, 5, 0, 4)<<endl;
    cout<<find_index_loop(array, 0, 0, 4)<<endl;
}