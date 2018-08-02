#include<iostream>

using namespace std;

int get_max(int a, int b)
{
    return a>b? a: b;
}
int max_value(int (*array)[4], int row_num, int column_num)
{
    
    if(array==nullptr|| row_num+column_num==0||row_num<0||column_num<0)
        return -1;
    int **cost = new int*[row_num];

    for(int i =0; i< row_num; i++)
        cost[i] = new int[column_num];


    cost[row_num-1][column_num-1] = array[row_num-1][column_num-1];

    // cost[row_num-1][column_num-2] = array[row_num-1][column_num-1]+ array[row_num-1][column_num-2];

    // cost[row_num-2][column_num-1] = array[row_num-2][column_num-1] + array[row_num-1][column_num-1];
   for(int i=column_num-2; i>=0; i--)
   {
       cost[row_num-1][i] = cost[row_num-1][i+1] + array[row_num-1][i];
   }

   for(int i = row_num-2; i>=0; i--)
     cost[i][column_num-1] = cost[i+1][column_num-1] + array[i][column_num-1];
   
   cout<<"over____"<<endl;
   for(int row=row_num-2; row >=0; row--)
     for(int column=column_num-2; column>=0; column--)
        {   
            // cout<<"row: "<<row<<" || column: "<<column<<endl;
            cost[row][column] = get_max(cost[row+1][column], cost[row][column+1])+array[row][column];
        }

   for(int i=0; i<row_num; i++)
    {
        for(int j=0; j< column_num; j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }
   int max_val = cost[0][0];
   delete[] cost;
   return max_val;
}


int main()
{
    int array[][4] = {{1, 10, 3, 8}, 
                     {12, 2, 9, 6},
                     {5, 7, 4, 11},
                     {3, 7, 16, 5}};

    int result = max_value(array, 4, 4);
    cout<<result<<endl;

}