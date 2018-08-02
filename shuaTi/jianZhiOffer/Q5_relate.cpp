#include<iostream>
using namespace std;
/**
the related question of Q5.
insert A2 to A1
*/

bool insert(int *A1, int a1_len, const int *A2, int a2_len, int max_len)
{
  if (A1 == nullptr || a1_len<=0 || a2_len<=0|| A2 == nullptr|| max_len <=0 )
    return false;
  
  int behind_index = a1_len + a2_len -1;
  if(behind_index+1 > max_len)
    return false;
  for(int front_index = a1_len - 1, a2_index = a2_len-1;
      front_index>=0 && a2_index>=0;)
  {
    if (A1[front_index] > A2[a2_index])
    {
        A1[behind_index--] = A1[front_index--];
    }
    else
    {
        A1[behind_index--] = A2[a2_index--];
    }
  }
  return true;

}

int main()
{
  int A1[100] = {1, 4, 6, 8};
  int a1_len = 4;

  int A2[3] = {2, 5, 7};
  int a2_len = 3;

  insert(A1, 4, A2, 3, 100);

  for (int i =0; i< a1_len+a2_len; i++)
  {
    cout<<A1[i]<<endl;
  }  
}