#include<iostream>
#include<string>
#include <limits>
using namespace std;

int main()
{
    cout << "type: \t\t" << "************size**************" << endl;
    cout << "bool: \t\t" << "bytes:" << sizeof(bool);
    cout << "\tmax_value:" << (numeric_limits<bool>::max)();
    cout << "\t\tmin_value:" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "bytes:" << sizeof(char);
    cout << "\tmax_value:" << (numeric_limits<char>::max)();
    cout << "\t\tmin_value:" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "bytes:" << sizeof(signed char);
    cout << "\tmax_value:" << (numeric_limits<signed char>::max)();
    cout << "\t\tmin_value:" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "bytes:" << sizeof(unsigned char);
    cout << "\tmax_value:" << (numeric_limits<unsigned char>::max)();
    cout << "\t\tmin_value:" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "bytes:" << sizeof(wchar_t);
    cout << "\tmax_value:" << (numeric_limits<wchar_t>::max)();
    cout << "\t\tmin_value:" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "bytes:" << sizeof(short);
    cout << "\tmax_value:" << (numeric_limits<short>::max)();
    cout << "\t\tmin_value:" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "bytes:" << sizeof(int);
    cout << "\tmax_value:" << (numeric_limits<int>::max)();
    cout << "\tmin_value:" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "bytes:" << sizeof(unsigned);
    cout << "\tmax_value:" << (numeric_limits<unsigned>::max)();
    cout << "\tmin_value:" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "bytes:" << sizeof(long);
    cout << "\tmax_value:" << (numeric_limits<long>::max)();
    cout << "\tmin_value:" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "bytes:" << sizeof(unsigned long);
    cout << "\tmax_value:" << (numeric_limits<unsigned long>::max)();
    cout << "\tmin_value:" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "bytes:" << sizeof(double);
    cout << "\tmax_value:" << (numeric_limits<double>::max)();
    cout << "\tmin_value:" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "bytes:" << sizeof(long double);
    cout << "\tmax_value:" << (numeric_limits<long double>::max)();
    cout << "\tmin_value:" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "bytes:" << sizeof(float);
    cout << "\tmax_value:" << (numeric_limits<float>::max)();
    cout << "\tmin_value:" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "bytes:" << sizeof(size_t);
    cout << "\tmax_value:" << (numeric_limits<size_t>::max)();
    cout << "\tmin_value:" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "bytes:" << sizeof(string) << endl;
    // << "\tmax_value:" << (numeric_limits<string>::max)() << "\tmin_value:" << (numeric_limits<string>::min)() << endl;
    cout << "type: \t\t" << "************size**************" << endl;
    return 0;
}
