//
// Created by 文健蔚 on 2016/12/17.
//

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::end;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    // init
    vector<int> vec(ia, end(ia));
    list<int> lst(vec.begin(), vec.end());

    // remove odd value
    for(auto it = lst.begin();  it != lst.end(); )
        if(*it & 0x1)
            it = lst.erase(it);
        else
            ++it;

    // remove even value
    for(auto it = vec.begin();  it != vec.end(); )
        if(! (*it & 0x1))
            it = vec.erase(it);
        else
            ++it;

    // print
    cout << "list : ";
    for(auto i : lst)   cout << i << " ";
    cout << "\nvector : ";
    for(auto i : vec)   cout << i << " ";
    cout << std::endl;

    return 0;
}
