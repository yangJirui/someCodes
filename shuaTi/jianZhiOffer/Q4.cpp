#include<iostream>
using namespace std;

bool find(const int (*array) [4], int row, int column, int num)
{
   if (array == nullptr || row<=0 || column <=0)
    return false;
   
   int top_row = 0, top_column = column -1;

   

   while((top_row>=0)&&(top_row<row)&&(top_column>=0)&&(top_column<column))
   {
     int top = array[top_row][top_column];
     cout<<top<<endl;
     
     if (top == num)
        return true;
     if (num>top)
     {
        top_row ++;
     }
     else
        top_column --;

   }
   return false;
}

void test()
{
    int array[4][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    bool result = find(array, 4, 4, 6);
    cout<<"***"<<endl;
    cout<<result<<endl;
}

int main()
{
    test();
}