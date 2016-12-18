//
// Created by annsshaodw on 2016/12/18.
//

#include <iterator>
#include <iostream>
#include <string>
#include <cstddef>

using std::cout;
using std::endl;
using std::string;

auto replace_with_pos(string &s, string const& oldVal, string const& newVal)
{
    for (size_t pos = 0; pos <= s.size() - oldVal.size();)
        if (s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal)
            s.replace(pos, oldVal.size(), newVal),
                    pos += newVal.size();
        else
            ++pos;
}

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
        if (oldVal == string{ cur, cur + oldVal.size() })
            cur = s.erase(cur, cur + oldVal.size()),
            cur = s.insert(cur, newVal.begin(), newVal.end()),
            cur += newVal.size();
        else
            ++cur;
}

int main()
{
    string s{ "AAA BBB CCC thru DDD EEE tho FFF GGG" };
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    replace_with_pos(s,"AAA","aaa");
    replace_with_pos(s,"BBB","bbb");
    cout << s << endl;

    return 0;
}
