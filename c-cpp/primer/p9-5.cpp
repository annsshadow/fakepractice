//
// Created by annsshadow on 2016/12/14.
//

auto find(vector<int>::const_iterator first, vector<int>::const_iterator last, int value)
{
    for(; first != last; ++first)
        if(*first == value) return first;
    return last;
}
