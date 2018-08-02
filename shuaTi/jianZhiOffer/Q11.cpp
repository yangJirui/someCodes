
#include<iostream>
using namespace std;

int find_min_inorder(const int* array, int length)
{
    int min = array[0];

    for(int i =1; i<length; i++)
    {
        if(array[i]<min)
            min = array[i];
    }

    return min;
}
int find_min(const int *array, int length)
{
    if(array == nullptr|| length <1)
        return -1;

    int st = 0;
    int end = length-1;

    if(array[st]<array[end])
        return array[0];
    
    int mid = (st+end)/2;
    while(st<end)
    {
        if (array[st]==array[mid]&& array[mid]==array[end])
            return find_min_inorder(array, int length);
        if (array[mid]>=array[st])
            st = mid +1;
        else
            end = mid;
        mid = (st + end )/2;
    }

    return array[mid];
}


int main()
{
    int array[] = {1, 0, 1, 1, 1};
    int a = find_min(array, 5);

    cout<<a<<endl;
}