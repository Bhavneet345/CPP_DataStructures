#include<iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *input, int size){
    unordered_map<int, int> map;
    int ans = 0;
    for(int i = 0; i < size; i++){
        if(!map.empty() && map.find(-input[i]) != map.end()){
            ans += map[-input[i]];
        } 
        map[input[i]] += 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}