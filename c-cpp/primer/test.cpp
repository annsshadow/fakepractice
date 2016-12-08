
#include <iostream>
#include <string>
using namespace std;

/*
cout << "Please enter two number:" << endl;
int num1 = 0, num2 = 0;
//cin >> num1 >> num2;
num1 = 1;
num2 = 2;
cout << "sum of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;

int sum = 0, value = 0, currentValue = 0;
if(cin >> currentValue)
{
    int count = 1;
    while(cin >> value)
    {
        if(value == currentValue)
        {
            count++;
        }
        else
        {
            cout << "currentValue is : " << currentValue << " occurs " << count << " times " << endl;
            currentValue = value;
            count = 1;
        }
        sum += value;
    }
}

cout << "sum is : " << sum << endl;

return 0;
*/
/*用法一：
*用str替换指定字符串从起始位置pos开始长度为len的字符
*string& replace (size_t pos, size_t len, const string& str);
*/

/*string line = "test;testtt;jjjjj;";
line = line.replace(line.find(";"), line.length(), "\n"); //从第一个@位置替换第一个@为空
cout << line << endl;
*/

/*
string s1, s2, s3;
s1 = s2 = "1\n34\n678\n0";
s3 = "\t10.10.10.10";
s1.insert(2, s3);
cout << s1 << endl;
//s2.insert(5, "bbb");
//cout << s2 << endl;
*/

class ClxBase
{
public:
    ClxBase()
    {
        cout << "base construct!" << endl;
    };
    virtual ~ClxBase()
    {
        cout << "base destruct！" << endl;
    };
    virtual void DoSomething()
    {
        cout << "base sth!" << endl;
    };
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived()
    {
        cout << "children1 construct!" << endl;
    };
    ~ClxDerived()
    {
        cout << "children1 destruct！" << endl;
    };
    void DoSomething()
    {
        cout << "children1 sth!" << endl;
    };
};

class ClxDerived2 : public ClxBase
{
public:
    ClxDerived2()
    {
        cout << "children2 construct!" << endl;
    };
    ~ClxDerived2()
    {
        cout << "children2 destruct！" << endl;
    };
    void DoSomething()
    {
        cout << "children2 sth" << endl;
    };
};

int   main()
{
    ClxBase *p =  new ClxDerived;
    p->DoSomething();
    p = new ClxDerived2;
    p->DoSomething();
    delete p;

    return 0;
}
