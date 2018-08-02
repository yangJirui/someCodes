#include<iostream>
using namespace std;


int get_sum(int num)
{
    int sum = 0;
    while(num>=10)
    {
        int yuShu = num % 10;
        num = num / 10;
        sum += yuShu;
    }

    return sum+num;
}

int run_core(int st_row, int st_column, int row_num, int column_num, int limited, bool* flag)
{
   int count = 0;
   if(st_row>=0&&st_row<row_num&&
      st_column>=0&&st_column<column_num&&
      get_sum(st_row)+get_sum(st_column)<=limited&&
      !flag[st_row*column_num+st_column])
   {
       flag[st_row*column_num+st_column] = true;
       count++;
       count  = count+run_core(st_row-1, st_column, row_num, column_num, limited, flag)
                     +run_core(st_row+1, st_column, row_num, column_num, limited, flag)
                     +run_core(st_row, st_column-1, row_num, column_num, limited, flag)
                     +run_core(st_row, st_column+1, row_num, column_num, limited, flag);
   }
   
   return count ;
}
int run_matrix(int row_num, int column_num, int limited)
{

    if(row_num<=0||column_num<=0||limited<0)
        return 0;
    bool * flag = new bool[row_num*column_num];
    for(int i=0; i< row_num*column_num; i++)
        flag[i] = false;

    int num_box = run_core(0, 0, row_num, column_num, limited, flag);
    delete[] flag;
    return  num_box;
}

int test_get_sum()
{
    cout<<get_sum(38)<<endl;
}
int main()
{
    cout<<run_matrix(10, 10, 5)<<endl;
    // test_get_sum();
}

