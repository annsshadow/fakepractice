//
// Created by annsshadow on 2016/12/23.
//

#include <iostream>
#include <vector>
#include <list>

// p16-19
template<typename Container>
std::ostream& print(Container const& container, std::ostream& os)
{
    for(typename Container::size_type i = 0; i != container.size(); ++ i)
        os << container[i] << " ";
    return os;
}

// p16-20
template<typename Container>
std::ostream& print2(Container const& container, std::ostream &os)
{
    for(auto curr = container.cbegin(); curr != container.cend(); ++curr)
        os << *curr << " ";
    return os;
}


int main()
{
    std::vector<int> v = { 1, 23, 6, 4, 5, 7, 4 };
    std::list<std::string> l = { "ss", "hh", "aa", "dd", "oo"," ww" };
    print2(v, std::cout) << std::endl;
    print2(l, std::cout) << std::endl;

    return 0;
}
