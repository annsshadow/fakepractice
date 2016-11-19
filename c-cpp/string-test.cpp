#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

    string s1 = "testtest";
    string s2 = s1;
    string s3 (s1);
    cout << "s1 length: " << s1.length() << endl;
    cout << "s1 size: " << s1.size() << endl;
    cout << "s2 length: " << s2.length() << endl;
    cout << "s2 size: " << s2.size() << endl;
    cout << "s3 length: " << s3.length() << endl;
    cout << "s3 size: " << s3.size() << endl;

    return 0;
}
