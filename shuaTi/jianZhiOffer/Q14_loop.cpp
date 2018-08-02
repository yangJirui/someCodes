#include<iostream>

using namespace std;


int cut_loop(int length)
{

    if(length <2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int *max_results = new int[length+1];

    max_results[0] = 0;
    max_results[1] = 1;
    max_results[2] = 2;
    max_results[3] = 3;


    for(int i=4; i<=length; i++)
    {
        int max=0;
        
        for(int j=1; j<i/2+1; j++)
        {
            int result = max_results[j]*max_results[i-j];
            if(max<result)
                max = result;
            max_results[i] = max;
        }
    }
   delete[] max_results;
    return max_results[length];
}


int main()
{
    cout<<cut_loop(8)<<endl;
}