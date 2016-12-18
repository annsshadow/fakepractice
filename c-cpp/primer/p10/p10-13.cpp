//
// Created by annsshadow on 2016/12/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool predicate(const std::string &s)
{
    return s.size() >= 5;
}

int main()
{
    auto v = std::vector<std::string>{ "aaa", "bbbb", "ccccc", "dddddd", "eeeee", "ffff" };
    auto pivot = std::partition(v.begin(), v.end(), predicate);

    for (auto it = v.cbegin(); it != pivot; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}

