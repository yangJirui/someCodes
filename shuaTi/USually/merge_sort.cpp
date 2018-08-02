#include<iostream>

using namespace std;


void merge(int* array1, int array_size1, int* array2, int array_size2)
{

    int *tmp = new int[array_size1+array_size2];

    int i=0, j=0, k=0;

    while(i<array_size1 && j<array_size2)
    {
        if(array1[i] < array2[j])
        {
            tmp[k++] = array1[i++];
        }
        else
            tmp[k++] =array2[j++];
    }

    while(i<array_size1)
    {
        tmp[k++] = array1[i++];
    }

    while(j<array_size2)
        tmp[k++] = array2[j++];

    for(int i=0; i<array_size1+array_size2; i++)
    {
        array1[i] = tmp[i];
    }
}

void merge_sort(int *array, int size)
{
    if(array==nullptr || size<2)
        return;

    int mid = (size)>>1;
    int *array1 = array;
    int array_size1 = mid;

    int *array2 = array + mid;
    int array_size2 = size - array_size1;
    merge_sort(array1, array_size1);
    merge_sort(array2, array_size2);

    merge(array1, array_size1, array2, array_size2);
}


int main()
{   
    int array[] = {3, 2, 21, 1, 0, 9};
    merge_sort(array, 6);

    for(int i=0; i<6; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}