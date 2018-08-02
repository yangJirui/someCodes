
#include<iostream>
using namespace std;


void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int find_kth_num(int* array, int st, int end, int k_index)
{
    /*找出第k大的数*/

    if(array==nullptr)
        return -1;
    if(st==end)
        return array[st];


    int choosed_index = rand()%(end+1) + st;

    int compare_value = array[choosed_index];

    swap(array[choosed_index], array[end]); //swap到最后一个

    int small= st-1;
    for(int index = st; index<end; index++)
    {
        if(array[index]<compare_value)
        {   
            small++;
            if(index>small)
                swap(array[index], array[small]);
        }
    }

    small++;
    swap(array[small], array[end]);
    
    if(small==k_index)
        return array[small];
    if(small<k_index)
        return find_kth_num(array, small+1, end, k_index);
    if(small>k_index)
        return find_kth_num(array, st, small-1, k_index);
}


int main()
{
//   int array[] = {1, 5, 3, 2, 4};

//   swap(array[0], array[4]);
  int N = 5;
//   int k = 2;
//   int k_index = N-k;
  for(int i =0; i<N; i++)
  {   
      int array[] = {1, 5, 3, 2, 4};
      cout<<find_kth_num(array, 0, N-1, i)<<endl;
    // cout<<array[i]<<endl;
  }

}