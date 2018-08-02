#include<iostream>

using namespace std;


void exchange(int &a, int &b)
{
    int tmp = a;

    a = b;
    b = tmp;
}
void quick_sort_low_to_high(int * array, int st, int end)
{
    if(array==nullptr)
        return;
    if(st>=end)
        return;

    int rand_index = rand()%(end-st) + st; //不用st-end + 1应为最后一个没必要随机到

    int compared_value = array[rand_index];
    exchange(array[end], array[rand_index]);

    int small= st-1;

    for(int i=st; i<end; i++)
    {
        if(array[i]<compared_value)
        {
            small++;
            if(small != i)
                exchange(array[small], array[i]);
        }
    }
    small++;
    exchange(array[small], array[end]);

    quick_sort_low_to_high(array, st, small-1);
    quick_sort_low_to_high(array, small+1, end);

}

void print_list(int *array, int st, int end)
{   
    cout<<"st:: "<<st<<" | end:: "<<end<<endl;
    for(int i=st; i<=end; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}


int main()
{
    int array[] = {1, 3, 2, 4, 9, 0};
    int N= 6;
    // quick_sort_low_to_high(array, 0, N-1);
    // quick_sort_high_to_low(array, 0, N-1);
    quick_sort_low_to_high(array, 0, N-1);
    for(int i=0; i< N; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}