#include<iostream>
#include<cstring>
using namespace std;


void change(int * str, int length)
{
    if (str == nullptr)
        // throw new std::exception::exception("str is nullptr");
        return ;
    if (length==1)
        return ;

    int p_front = 0;
    int p_behind = length-1;

    while(p_front <=p_behind)
    {
        while (str[p_behind] & 0x1 == 0)
                p_behind--;
            

        while(str[p_front] & 0x1  == 1)
                p_front++;
          

        int tmp = str[p_behind];
        str[p_behind] = str[p_front];
        str[p_front] = tmp;
        cout<<"p1: "<<p_front<<endl;
        cout<<"p2: "<<p_behind<<endl;
        cout<<"***"<<endl;
        p_behind--;
        p_front++;
    }

}


int main()
{
    int num[] = {1, 2, 2, 2, 2};
    
    int N = 5;
    change(num, N);

    for(int i = 0; i<N; i++)
    {
        cout<<num[i]<<endl;
    }
}