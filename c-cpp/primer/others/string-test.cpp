#include <string>
#include <vector>
#include <iostream>

using namespace std;
using std::vector;

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
    cout << "'a' size: " << sizeof('a') << endl;
    cout << "\"a\" size: " << sizeof("a") << endl;


    string line;
    //while(cin >> word)
    //while(getline(cin, line))
    //    if(!line.empty())
    //        cout << line << endl;

    string s4("");
    char c1[3] = {0};

    c1[0] = 'a';
    c1[1] = 'A';
    c1[2] = 'b';
    vector<char> vc1(begin(c1), end(c1));

    for(auto v : c1)
    {
        cout << "c1-v: " << v << endl;
    }

    for(auto v : vc1)
    {
        cout << "c1-v-v: " << v << endl;
    }

    string s5('a','b');
    char c2 = 'a';
    cout << "a-ascii: " << static_cast<int>(c2) << endl;
    //cout << "s5: " << s5 << endl;

    //overflow
    //s4 += c1;
    //cout << "s4 + c1: " << s4 << endl;

    return 0;
}
