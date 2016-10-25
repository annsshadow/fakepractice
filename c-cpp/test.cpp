#include <boost/regex.hpp>
#include <iostream>
#include <string>
using namespace std;
int main()
{
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

    string line = "test;testtt;jjjjj;";
    line = line.replace(line.find(";"), line.length(), "\n"); //从第一个@位置替换第一个@为空
    cout << line << endl;
    return 0;
}
