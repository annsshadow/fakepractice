//
// Created by annsshadow on 2016/12/23.
//

#include <iostream>
#include <random>

// default version
unsigned random_gen();
// with seed spicified
unsigned random_gen(unsigned seed);
// with seed and range spicified
unsigned random_gen(unsigned seed, unsigned min, unsigned max);
int main()
{
    std::string temp;
    while(std::cin >> temp)
        std::cout << std::hex << random_gen(1, 10, 100) << std::endl;
    return 0;
}

unsigned random_gen()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

unsigned random_gen(unsigned seed)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

unsigned random_gen(unsigned seed, unsigned min, unsigned max)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud(min, max);
    return ud(e);
}
