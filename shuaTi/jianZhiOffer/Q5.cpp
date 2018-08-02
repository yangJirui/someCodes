#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;


bool change(char *str, int max_length)
{
    if (str == nullptr || max_length<=0)
        return false;
    int length = strlen(str);
    cout<<length<<endl;
    cout<<"****"<<endl;
    int space_count = 0;
    for(int i=0; i< length; i++)
    { 
        if (str[i] == ' ')
            space_count++;
    }

    int new_length = length + space_count*2;
    
    if (new_length > max_length)
    {
        cout<<"new_length out of max_length, erro"<<endl;
        return false;
    }
    int behind_index = new_length;
    // int front_index = length; 
    
    for(int front_index= length; front_index>=0 && behind_index> front_index; front_index--)
    {
        cout<<front_index<<endl;

        if (str[front_index]!= ' ')
            str[behind_index--] = str[front_index];
        else
        {   
            cout<<behind_index<<endl;
            str[behind_index--] = '0';
            str[behind_index--] = '2';
            str[behind_index--] = '%';
        }
    }
    return true;
}

void test_1()
{
    char str[100] = "  aa a ";
    printf("original:\n");
    printf("%s\n", str);
    printf("after_change:\n");
    change(str, 100);
    printf("%s\n", str);
}


// bool change_2(const char * str)
// {
//     int length = strlen(str);
//     if (str == nullptr|| length < 0)
//         return false;
//     string new_str;
//     for(int i =0 ; i <length; i++)
//     {
//         if (str[i] == ' ')
//         {
//          new_str += "%20";
//         }
//         else new_str += str[i];
//     }
//     if (!new_str.empty()) cout<<new_str<<endl;
//     else cout<<"no space in the str"<<endl;
//     return true;
// }

// void test()
// {
//     char *str = "We are  happy ";

//     change_2(str);
// }

int main()
{
    test_1();
    // char * str = "test";
    // string a = str;
    // cout<<a<<endl;
}