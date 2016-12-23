//
// Created by annsshadow on 2016/12/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename T, unsigned size>
T* mybegin(T(&arr)[size])
{
    return arr;
}

template<typename T, unsigned size>
T* myend(T (&arr)[size])
{
    return arr + size;
}

int main()
{
    std::string s[] = { "sssss","hhhhh","aaaaaa","ddddd" };
    std::cout << *(mybegin(s)+1) << std::endl;
    std::cout << *(myend(s) - 1) << std::endl;
    return 0;
}
