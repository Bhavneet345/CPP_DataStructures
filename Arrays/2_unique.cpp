#include<iostream>
using namespace std;

void findUnique(int arr[], int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }
    cout << ans << endl;
    int pos = 0;
    while((ans & 1) == 0){
        pos++;
        ans >>= 1;
    }
    cout << pos << endl;
    int mask = (1 << pos);
    int first = 0, second = 0;
    for(int i = 0; i < n; i++){
        if((arr[i] & mask) == 0){
            first ^= arr[i];
        }
        else{
            second ^= arr[i];
        }
    }
    cout << first << " " << second << endl;
    return;
}

int main(){
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7};
    findUnique(arr, 12);
    return 0;
}