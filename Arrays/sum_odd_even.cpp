#include<iostream>
#include<string>
using namespace std;

int convert_to_integer(string num){
    int result = 0;
    for(int i = 0; i < num.length(); i++){
        result += (num[i] - '0') * pow(10, num.length() - (i + 1));
    }
    return result;
}

int main(){
    // int num, even = 0, odd = 0;
    // cin >> num;
    // string temp = to_string(num);
    // for(int i = 0; i < temp.length(); i++){
    //     if((i + 1) % 2 != 0){
    //         odd += temp[i] - '0';
    //     }
    //     else{
    //         even += temp[i] - '0';
    //     }
    // } 
    // cout << even << "\n" << odd;
    // return 0;
    cout << convert_to_integer("120");
    return 0;
}