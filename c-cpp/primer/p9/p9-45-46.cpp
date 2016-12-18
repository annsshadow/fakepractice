//
// Created by annsshadow on 2016/12/18.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

auto add_pre_and_suffix(std::string name, std::string const& pre, std::string const& su)
{
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

auto add_pre_and_suffix_pos(string name, string const& pre, string const& su)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    return name.append(su);
}


int main()
{
    string name("annsshadow");
    cout << add_pre_and_suffix(name, "Mr.", ",Jr.") << endl;
    string name2("shadow");
    cout << add_pre_and_suffix_pos(name2,"Mr.",",Jr.") << endl;
    return 0;
}

