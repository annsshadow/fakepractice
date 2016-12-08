#include <vector>
#include <iostream>

using namespace std;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto &i : v)
    {
        i *= i;
    }
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    string s("just some string");
    if(s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;

    return 0;
}
