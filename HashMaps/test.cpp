#include<iostream>
#include "ourmap.h"
using namespace std;

int main()
{
    map<int>mymap(5);
    for(int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        mymap.insert(key, i + 1);
        cout << mymap.getloadFactor() << endl;
    }
    cout << "Size : " << mymap.getSize() << endl;
    for(int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << ": " << mymap.getvalue(key) << endl;
    }
    for(int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << "removing " << key << " " << "with value " << mymap.deleteKey(key) << endl;
    }
    char c = '0' + 0;
    string key = "abc";
    key += c;
    cout << key << ": " << mymap.getvalue(key) << endl;
    cout << "Size : " << mymap.getSize() << endl;
    return 0;
}