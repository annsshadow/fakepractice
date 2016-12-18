//
// Created by annsshadow on 2016/12/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);

    auto pivot = partition(vs.begin(), vs.end(), [sz](const std::string &s){
        return s.size() >= sz;}
    );

    for(auto it = vs.cbegin(); it != pivot; ++it)
        std::cout << *it << " ";
}


void biggies_stable_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);

    auto pivot = stable_partition(vs.begin(), vs.end(), [sz](const std::string& s){
        return s.size() >= sz;
    });

    for(auto it = vs.cbegin(); it != pivot; ++it)
        std::cout << *it << " ";
}


int main()
{
    std::vector<std::string> v{
            "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };

    std::cout << "p10-18: ";
    std::vector<std::string> v1(v);
    biggies_partition(v1, 4);
    std::cout << std::endl;

    std::cout << "p10-19: ";
    std::vector<std::string> v2(v);
    biggies_stable_partition(v2, 4);
    std::cout << std::endl;

    return 0;
}
