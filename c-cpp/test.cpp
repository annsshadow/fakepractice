
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
    /*�÷�һ��
    *��str�滻ָ���ַ�������ʼλ��pos��ʼ����Ϊlen���ַ�
    *string& replace (size_t pos, size_t len, const string& str);
    */

    /*string line = "test;testtt;jjjjj;";
    line = line.replace(line.find(";"), line.length(), "\n"); //�ӵ�һ��@λ���滻��һ��@Ϊ��
    cout << line << endl;
    */
    string s1, s2, s3;
    s1 = s2 = "1\n34\n678\n0";
    s3 = "\t10.10.10.10";
    s1.insert(2, s3);
    cout << s1 << endl;
    //s2.insert(5, "bbb");
    //cout << s2 << endl;
    return 0;
}
