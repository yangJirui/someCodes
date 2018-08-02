#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class Mystring
{
public:
    Mystring(char *mydata);
    Mystring(const Mystring &str);
    ~Mystring(void);
    
    Mystring& operator=(const Mystring& str);
    void Print();

private:
    char * data;
};


Mystring::Mystring(char *mydata)
{
    if (mydata == nullptr)
    {
        data = new char[1];
        data[0] = '\0';
    }
    else
    {
        int len = strlen(mydata);
        data = new char[len +1];
        strcpy(data, mydata);
    }
}

Mystring::Mystring(const Mystring& str)
{
    int len = strlen(str.data);
    data = new char[len + 1];
    strcpy(data, str.data);
}

Mystring::~Mystring()
{
    delete[] data;
}

Mystring& Mystring::operator = (const Mystring& str)
{
    if (this == &str)
        return *this;

    delete[] data;
    data = nullptr;

    int len = strlen(str.data);
    data = new char[len+1];
    strcpy(data, str.data);

    return *this;
}


void Mystring::Print()
{
    printf("%s", data);
}


void Test1()
{
    cout<<"test1..."<<endl;

    char* text = "hello World";

    Mystring str1(text);
    Mystring str2 = str1;
    
    printf("the expected result is : %s .\n", text);

    cout<<"the actual result is: "<<endl;
    str2.Print();

}

int main()
{
    Test1();
}