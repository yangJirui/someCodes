#include<iostream>

using namespace std;

int get_min(int a, int b, int c)
{
    int min = a>b? b: a;

    return min>c? c: min;
}
int get_ugly(int index)
{


    int* ugly_array = new int[index];
    
    ugly_array[0] = 1;
    int next_ugly_index = 1;

    int *ugly_multi2 = ugly_array;
    int *ugly_multi3 = ugly_array;
    int *ugly_multi5 = ugly_array;

    while(next_ugly_index<index)
    {
        int min = get_min(*ugly_multi2*2, *ugly_multi3*3, *ugly_multi5*5);

        ugly_array[next_ugly_index] = min;

        while(*ugly_multi2*2<=min)
            ugly_multi2++;
        while(*ugly_multi3*3<=min)
            ugly_multi3++;

        while(*ugly_multi5*5<=min)
            ugly_multi5++;

        next_ugly_index++;
    }

    int ugly = ugly_array[index-1];
    delete[] ugly_array;
    
    return ugly;
}


int main()
{
    cout<<get_ugly(4)<<endl;

}