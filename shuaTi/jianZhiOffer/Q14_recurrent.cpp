#include<iostream>
using namespace std;



int cut_core(int length)
{

    int max = 0;
    
    if(length==1)
        return 1;
    if(length==2)
        return 2;
    if(length==3)
        return 3;
    
    for(int i=1; i< length; i++)
    {
        int value = cut_core(i)*cut_core(length-i);

        if(max<value) max = value;
    }

    return max;

}
int cut_recurrent(int length)
{
    if (length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;
    return cut_core(length);
}


int main()
{
    cout<<cut_recurrent(8)<<endl;
}