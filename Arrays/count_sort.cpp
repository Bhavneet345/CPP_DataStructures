#include<iostream>
using namespace std;

void returnCountSorted(int *arr, int n, int k){
    int *freq = new int[k + 1];
    int *pos = new int[k + 1];
    int *res = new int[n];
    pos[0] = 0;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    for(int i = 1; i < k + 1; i++){
        pos[i] = pos[i - 1] + freq[i - 1];
    }
    for(int i = 0; i < k + 1; i++){
        cout << pos[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        int position = pos[arr[i]];
        if(position < n){
            res[position] = arr[i];
        }
        pos[arr[i]] += 1;
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    return;
}

int main(){
    int arr[9] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
    returnCountSorted(arr, 9, 3);
    return 0;
}