#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int>map;
    
    //insert and update using []
    map["abc"] = 1;
    pair<string, int>p("def", 1);
    map.insert(p);

    //to access value to coressponding key
    cout << map["abc"] << endl; //creates if doesnot exists
    cout << map.at("def") << endl;

    // to check presence
    try
    {
        if(map.count("ghi") > 0)
        {
            cout << "Key present" << endl;
        }   
        else
        {
            string input = "ghi";
            throw(input);
        }
    }
    catch(string key)
    {
        cout << key << " " << "Key not present" << endl;
    }   

    //to check size
    cout << map.size() << endl;
    
    //to erase
    map.erase("def");
    cout << map.size() << endl;
    return 0;
}