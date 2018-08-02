#include<iostream>

using namespace std;


bool find_core(const char* matrix, bool *flag, const char* str, int index, int length,int row_num, int column_num,
               int row, int column)
{
    if (index==length)
        return true;
    bool result = false;
    char cc = str[index];
    char mc = matrix[row*column_num+column];
//    cout<<"*"<<endl;
    if(row>=0&&row<row_num&&column>=0&&column<column_num && index<=length
       &&flag[row*column_num+column]!=true && matrix[row*column_num+column]==str[index])
    {
        index = index +1;
        flag[row*column_num+column] = true;
        result = find_core(matrix, flag, str, index, length, row_num, column_num,
                           row-1, column)||
                 find_core(matrix, flag, str, index, length, row_num, column_num,
                           row, column-1)||
                 find_core(matrix, flag, str, index, length, row_num, column_num,
                           row+1, column)||
                 find_core(matrix, flag, str, index, length, row_num, column_num,
                           row, column+1);
        if (!result)
        {
            // index --;
            flag[row*column_num+column] = false;
        }
    }

    return result;
}
bool find(const char *matrix, const char* str, int length, int row_num, int column_num)
{
    bool *flag = new bool[row_num*column_num];
    for(int i=0; i<row_num*column_num; i++)
    {
        flag[i] = false;
    }

    for(int row =0; row<row_num; row++)
        for(int column=0; column< column_num; column++)
        {
            if(find_core(matrix, flag, str, 0, length, row_num, column_num,
                         row, column))
                return true;
        }
    delete[] flag;
    return false;
}


void test()
{
    // char * matrix ={{'a', 'b', 't', 'g'},
    //                 {'c', 'f', 'c', 's'},
    //                 {'j', 'd', 'e', 'h'}};
    const char *matrix = "ABCESFCSADEE";
    const char *str =  "SEE";

    bool result = find(matrix, str, 3, 3, 4);
    cout<<result<<endl;
}

int main()
{
    test();
}