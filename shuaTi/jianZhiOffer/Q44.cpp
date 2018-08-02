#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int beginNumbers(int digits)
{
    if(digits==1)
        return 0;
    return (int)pow(10, digits-1);
}

int countOfIntegers(int digits)
{   
    //digits为位的个数
    if(digits == 1)
        return 10;

    int count = (int) pow(10, digits-1);

    return 9*count;
}

int digitAtIndex(int index, int digits)
{
    int number = beginNumbers(digits) + index/digits;
    int indexFromRight = digits - index%digits;

    for(int i = 1; i< indexFromRight; i++)
        number = number / 10;
    
    return number % 10;
}

int digitAtIndex(int index)
{
    if(index<0)
        return -1;

    int digits = 1;

    while(1)
    {
        int num_of_integes = countOfIntegers(digits);

        if(index<num_of_integes*digits)
            return digitAtIndex(index, digits);

        index = index - digits*num_of_integes;
        digits++;
    }
    return -1;

}


int get_weishu(int index)
{
    if(index<10)
        return 1;
    int weishu= 2;
    int total_weishu = 10;
    while(1)
    {    
        total_weishu += pow(10, weishu-1)*9*weishu;
        if(index>total_weishu)
            weishu++;
        else 
            break;
    }
    return weishu ;
}

int find_num(int index)
{   
    if (index<10)
        return index;
    int weishu = get_weishu(index);
    cout<<"the weishu is :"<< weishu<<endl;
    int left_limited = 10;
    
    int tmp = 2;
    while(tmp<weishu)
    {
        left_limited += pow(10, tmp-1)*9*tmp;
        tmp ++;
    } 

    index = index - left_limited;

    int num  = index /weishu;
    int sub_index = index % weishu;    
    int left_number = num + pow(10, weishu-1);
    cout<<left_number<<endl;
    string str = to_string(left_number);
    cout<<str[sub_index]<<endl;
    
    return str[sub_index] - '0';
}


int main()
{
    cout<<digitAtIndex(81)<<endl;

    cout<<"****"<<endl;

    cout<<find_num(81)<<endl;
}