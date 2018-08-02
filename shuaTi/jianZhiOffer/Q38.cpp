#include<iostream>
#include<cstring>
#include<vector>
using namespace std;


/********************************************************************************************

*
    [a, b, c]全部组合， 
    如aaa, aab, aac
      aba abb abc 这种。。
********************************************************************************************/
void print_all_possiable_string(char* str, char* print_str, int index, int N)
{
  
    if(str == nullptr|| print_str == nullptr)
        return ;
    if(index > N-1)
        {
            printf("%s\n", print_str);
            return ;
        }

    for(int i=0; i< N; i++)
    {  
       print_str[index] = str[i]; 
       print_all_possiable_string(str, print_str, index+1, N);
    }
} 


/********************************************************************************************

    输出abc的全部排列： abc, acb, bac, bca, cab, cba
 
********************************************************************************************/
void print_all_order(char* str, int st, int N)
{
   

    if(st>=N)
        {   printf("%s\n", str);
            return;}
    // printf("%s\n", str);
    for(int i=st; i< N; i++)
    {
        char tmp = str[st];
        str[st] = str[i];
        str[i] = tmp;
        print_all_order(str, st+1, N);
        tmp = str[st];
        str[st] = str[i];
        str[i] = tmp;
    }

}




/********************************************************************************************

    输出abc的全部组合：a， b, c, ab, ac, bc, abc
 
********************************************************************************************/
void print_v(vector<char>& v)
{
  if(v.size())
  {
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;
  }
}
void print_all_combination(char*str, int num, vector<char>& v)
{
    if(str==nullptr)
        return ;
    if(num == 0)
        {
            print_v(v);
            return;
        }
    if(*str == '\0')
        return ;
    v.push_back(*str);
    print_all_combination(str+1, num-1, v);
    v.pop_back();
    print_all_combination(str+1, num, v);
}

void print_all(char* str)
{
    
    vector<char> v;
    for(int i =1; i<=strlen(str); i++)
    { 
       print_all_combination(str, i, v);
    }
}




/********************************************************************************************

  //题目：输入两个整数n和m，从数列1,2,3...n中随意取几个数，使其和等于m，要求列出所有的组合。
 
********************************************************************************************/

int get_sum(vector<int>&v)
{
    int sum = 0;
    if(v.size())
    {
        for(auto i : v)
            sum += i;
    }
    return sum;
}
void print_sum_equal_core(int n, int index, int sum, int num_of_numbers, vector<int> &v)
{
    
    if(index>n+1)
        return ;

    if(num_of_numbers==0&&sum == get_sum(v))
    {
        for(auto i: v)
            cout<<i<<" ";
        cout<<endl;
        return ;
    }

    v.push_back(index);
    print_sum_equal_core(n, index+1, sum, num_of_numbers-1, v);
    v.pop_back();
    print_sum_equal_core(n, index+1, sum, num_of_numbers, v);
}
void print_sum_equal(int n, int m)
{
    
    vector<int> v;

    for(int i=1; i<=n; i++)
    {
        print_sum_equal_core(n, 1, m, i, v);
    }
}

/////快捷写法：
void print_sum_equal_m(int n, int m, vector<int>& v)
{ 
    if(n<0)
        return ;
    if(m==0)
    {
        for(auto i: v)
            cout<<i<<" ";
        cout<<endl;
        return ;
    }

    v.push_back(n);
    print_sum_equal_m(n-1, m-n, v);
    v.pop_back();
    print_sum_equal_m(n-1, m, v);

}



/********************************************************************************************

  //题目：输入两个整数n和m，从数列1,2,3...n中随意取m个数，使其和为sum，要求列出所有的组合。
 
********************************************************************************************/
void print_mNumber_euqal_sum(int n, int m, int sum, vector<int>&v)
{
    
   if(n<0)
      return ;
   if(v.size()==m &&sum == 0)
   {
    for(auto i: v)
            cout<<i<<" ";
        cout<<endl;
        return ;
   }

   v.push_back(n);
   print_mNumber_euqal_sum(n-1, m, sum-n, v);
   v.pop_back();
   print_mNumber_euqal_sum(n-1, m, sum, v);
}
//是不是还有更简便的算法？


int main()
{   
    char str[] = "abcd";
    int N = 3;
    char * print_str = new char[N+1];
    // print_all_possiable_string(str, print_str, 0, 3);
    // print_all_order(str, 0, 3);
    // print_all(str);
    // print_sum_equal(5, 4);
    std::vector<int> v;
    // print_sum_equal_m(5, 100, v);
    print_mNumber_euqal_sum(5, 3, 6, v);
}