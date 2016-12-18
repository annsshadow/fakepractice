#include "p7-11"

int main()
{
    Sales_data item1;
    print(std::cout, item1) << std::endl;

    Sales_data item2("01-002-0003-X");
    print(std::cout, item2) << std::endl;

    Sales_data item3("04-005-0006-Y", 2, 23.33);
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;

    return 0;
}
