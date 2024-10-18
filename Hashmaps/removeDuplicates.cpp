#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int *arr, int n){
    unordered_map<int, bool> map;
    // for(int i = 0; i < n; i++){
    //     map[arr[i]] = true;
    // }
    vector<int> res;
    // for(int i = 0; i < n; i++){
    //     if(map[arr[i]]){
    //         res.push_back(arr[i]);
    //         map[arr[i]] = false;
    //     }
    // }
    for(int i = 0; i < n; i++){
        if(map.count(arr[i]) > 0){
            continue;
        }
        res.push_back(arr[i]);
        map[arr[i]] = true;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> res = removeDuplicates(arr, n);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}