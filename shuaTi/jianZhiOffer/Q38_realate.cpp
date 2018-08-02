#include<iostream>
#include<vector>

using namespace std;



bool is_satisfy(int* array, int st, int N)
{
    if(array == nullptr)
        return false;
    if(st>=N)
        return false;

    int sum1 = (array[0]+array[1]+array[2]+array[3]);
    int sum2 = (array[4]+array[5]+array[6]+array[7]);
    int sum3 = (array[0]+array[2]+array[4]+array[6]);
    int sum4 = (array[1]+array[3]+array[5]+array[7]);
    int sum5 = (array[0]+array[1]+array[4]+array[5]);
    int sum6 = (array[2]+array[3]+array[6]+array[6]);
    if(sum1==sum2&& sum3==sum4&& sum5 == sum6)
    {
        for(int i=0; i< N; i++)
            cout<<array[i]<<" ";
        cout<<endl;
        return true;
    }
    for(int i=st; i<N; i++)
    {
        int tmp = array[st];
        array[st] = array[i];
        array[i] = tmp;

        is_satisfy(array, st+1, N);

        tmp = array[st];
        array[st] = array[i];
        array[i] = tmp;
    }
}

