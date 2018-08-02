#include<iostream>
#include<cstring>
using namespace std;


void find_longest_substr(char* str)
{
    if (str==nullptr)
        return ;
    int map[26];
    for(int i=0; i<26; i++)
        map[i] = -1;

    int *f = new int[strlen(str)];
    for(int i=0; i<strlen(str); i++)
        f[i] = 0;

    f[0] = 1;
    map[str[0]-'a'] = 0;

    int max_len = 0;
    int st = 0;
    for(int i=1; i< strlen(str); i++)
    {
        if (map[str[i]-'a'] == -1)
            f[i] = f[i-1] + 1;
        else
        {
            int d = i-map[str[i]-'a'];
            if(d<=f[i-1])
                f[i] = d;
            else
                f[i] = f[i-1] + 1;
        }
        map[str[i]-'a'] = i;

        if(max_len<=f[i])
        {
            max_len = f[i];
            st = i-max_len+1;
        }
    }
    cout<<"st:: "<<st<<endl;
    cout<<"len::"<<max_len<<endl;

    // for(int i=0; i<strlen(f))
}


void find_longest_substr_new(char* str)
{
    if(str==nullptr)
        return;

    int char_index_map[26];
    for(int i=0; i< 26; i++)
        char_index_map[i] = -1;

    int current_length = 0;
    int max_length=0;
    int st=0;

    for(int i=0; i<strlen(str); i++)
    {
        if(char_index_map[str[i] - 'a'] == -1)
            {
                // char_index_map[str[i]-'a'] = i;
                current_length ++;
            }
        else
        {
            int distance = i - char_index_map[str[i]-'a'];

            if(distance<=current_length)
                current_length = distance;
            else
                current_length++ ;
        }

        char_index_map[str[i] - 'a'] = i;

        if (current_length>=max_length)
        {
            max_length = current_length;
            st = i - max_length + 1;
        }
    }

    for(int i = 0; i<max_length; i++)
    {
        cout<<str[st+i]<<" ";
    }
    cout<<endl;
    cout<<"st is :: "<< st<<endl;
    cout<<"max_length is :: "<<max_length<<endl;
}

void find_longest_substr_2(char* str)
{
   // return longest substr

    int* char_index_map = new int[26];

    for (int i=0; i<26; i++)
        char_index_map[i] = -1;

    int st = 0;
    int max_length  = 0;
    int real_st = 0;
    for(int i=0; i< strlen(str); i++)
    {
        if (char_index_map[str[i]-'a'] != -1 && char_index_map[str[i]-'a'] >=st)
        {
            st = char_index_map[str[i]-'a'] + 1;
            
            cout<<"st is ::"<<st<<endl;
        }
        else
        {
            int distacne = (i - st)+1; 
            if ( distacne>=max_length)
            {
                max_length = distacne;
                real_st = st;
            }
        }
        

        char_index_map[str[i]-'a'] = i;

    }

    cout<<"max length is:: "<< max_length <<endl;
    for(int i = 0; i<max_length; i++)
    {
        cout<<str[real_st+i]<<" ";
    }
    cout<<endl;
}


void find_longest_substr_3(char* str) // 最简单
{
    int len = strlen(str);
    map<char, int > char_index_map;
    
    int max_len = 0;
    int st=0;// 用来记录最长不重复字串的起始
    for(int i=0; i<len; i++)
    {  
       char ch = str[i];
       if(char_index_map.count(ch) && st<=char_index_map[ch])
       {
          st = char_index_map[ch]+1;
       }
       
       max_len = max(max_len, i-st+1);
       char_index_map[ch] = i;
    }
    
    cout<<max_len<<;
    for(int i=0; i<max_len; i++)
    {
        cout<<str[st+i]<<" ";
    }
}
int main()
{
   char * str = "arabcaasdcfr";
   // find_longest_substr(str);

   find_longest_substr_new(str); 
   cout<<"++++"<<endl;   
   find_longest_substr_2(str);
}