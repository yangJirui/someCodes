# include<iostream>
# include<vector>
# include<string>

using namespace std;

void reverse(string& s, int st, int end)
{
    if (s.empty()) return;
    while (st <= end)
    {
        swap(s[st], s[end]);
        st++;
        end--;
    }

    return;
}

//实现split，并将split后的字符进行原地反转
void split_and_reverse(string& s, char ch)
{
    int st = 0;
    int end = st;
    if (s.length() <= 1) return;

    while (st < s.length() && s[st] == ch)
        st++;
    end = st;
    while (end < s.length() && st <= end)
    {
        while ((end + 1) < s.length() && s[end + 1] != ch)
            end++;

        reverse(s, st, end);
        end++;
        while (end < s.length() && s[end] == ch)
            end++;
        st = end;
    }

    return;
}

// 实现python的split函数
vector<string> split(string& s, char ch)
{
    int st = 0, end = 0;
    vector<string> s_list;

    while (st < s.length() && s[st] == ch)
        st++;
    end = st;
    while (end < s.length() && st <= end)
    {
        while ((end + 1) < s.length() && s[end + 1] != ch)
            end++;
        s_list.push_back(s.substr(st, end - st + 1));
        end++;
        while (end < s.length() && s[end] == ch)
            end++;
        st = end;
    }
    return s_list;
}

void print_vector(vector<string> & list)
{
    for (auto &v : list)
        cout << v << " ";
    cout << endl;
    return;
}
int main()
{
    string s = "asasd,,,,,,,,abcd,,,,,,";
    for (auto e : s)
        cout << e << " ";
    cout << endl;
    cout << "ssssssssss" << endl;
    split_and_reverse(s, ',');
    for (auto e : s)
        cout << e << " ";
    cout << endl;
    vector<string> list = split(s, ',');
    cout << "************" << endl;
    print_vector(list);

}