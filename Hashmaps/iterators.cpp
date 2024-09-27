#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int>map;
    map["abc1"] = 1;
    map["abc2"] = 2;
    map["abc3"] = 3;
    map["abc4"] = 4;
    map["abc5"] = 5;
    unordered_map<string, int> :: iterator it;
    for(it = map.begin(); it != map.end(); it++)
    {
        cout << "key : " << it -> first << "," << "pair : " << it -> second << endl;
    }
    return 0;
}