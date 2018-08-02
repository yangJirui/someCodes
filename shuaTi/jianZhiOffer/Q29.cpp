#include<iostream>
using namespace std;

void clock_print(int (*matrix)[4], int srow, int scolumn, int erow, int ecolumn)
{
    if(matrix==nullptr||srow>erow|| scolumn> ecolumn)
        return;
    if (srow<=erow&&ecolumn==scolumn)
    {
        for(int i=srow;i <=erow; i++)
            cout<<matrix[i][srow]<<" ";
        cout<<endl;
        return ;
    }
    if(srow==erow&& scolumn<=ecolumn)
    {
        for(int j=scolumn; j<=ecolumn; j++)
            cout<<matrix[srow][j];
        cout<<endl;
        return ;
    }
    for(int j = scolumn; j<=ecolumn; j++)
       cout<<matrix[srow][j]<<" ";
    cout<<endl;// di yi hang

    for(int i = srow+1; i<=erow; i++)
        cout<<matrix[i][ecolumn]<<" ";
    cout<<endl;// lie

    for(int j = ecolumn-1; j>=scolumn; j--)
        cout<<matrix[erow][j]<<" ";
    cout<<endl;
    for(int i = erow - 1; i>srow; i--)
        cout<<matrix[i][scolumn];
    cout<<endl;
    clock_print(matrix, srow+1, scolumn+1, erow-1, ecolumn-1);
}


int main()
{
    int matrix[][4] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11,12},
                       {13, 14, 15, 16}};
    clock_print(matrix, 0, 0, 3, 3);
}