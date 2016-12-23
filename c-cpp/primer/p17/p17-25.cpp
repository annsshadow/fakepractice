//
// Created by annsshadow on 2016/12/23.
//

#include <iostream>
#include <regex>
#include <string>

using namespace std;

string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
string fmt = "$2.$5.$7";
regex r(pattern);
string s;

int main()
{
    while(getline(cin,s))
    {
        smatch result;
        regex_search(s,result,r);
        if(!result.empty())
        {
            cout<<result.prefix()<<result.format(fmt)<<endl;
        }
        else
        {
            cout<<"Sorry, No match."<<endl;
        }
    }

    return 0;
}

