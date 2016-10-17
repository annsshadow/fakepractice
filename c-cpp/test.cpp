#include <iostream>

using namespace std;

int main()
{
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
}
