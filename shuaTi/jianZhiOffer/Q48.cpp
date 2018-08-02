#include<iostream>
#include<cstring>
using namespace std;


int find_long_substr(char* str)
{

    if(str==nullptr)
        return -1;

    int in_dict[26];

    for(int i =0; i<26; i++)
        in_dict[i] = -1;
    
    int longest_array[26];
    for(int i=0; i<26; i++)
        longest_array[i]=0;
    longest_array[0] = 1;
    in_dict[*str - 'a'] = 0;
    int max = longest_array[0];
    for(int i =1; i<strlen(str); i++)
    {
        if(in_dict[str[i]-'a'] == -1)
        {
            // in_dict[str[i]-'a'] = i;
            longest_array[i] = longest_array[i-1] + 1;
        }
        else
        {
          if(i-in_dict[str[i]-'a'] <=longest_array[i-1])
            longest_array[i] = i - in_dict[str[i] - 'a'];
          else
            longest_array[i] = longest_array[i-1] + 1;
        }
        in_dict[str[i] - 'a'] = i;
        if(longest_array[i]>max)
            max = longest_array[i];
    }

    return max;
}

int main()
{   
    char * str = "arabpcacfr";
    cout<<find_long_substr(str)<<endl;
}