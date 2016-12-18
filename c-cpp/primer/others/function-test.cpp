#include <iostream>
#include <typeinfo>

using namespace std;

string::size_type find_char(const string &s, char &c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    string s = "i am a string";
    char c = 'a';
    string::size_type occurs = 0;

    auto index = find_char(s, c, occurs);

    cout << "index: " << index << " type: " << typeid(index).name() << endl;

    return 0;
}
