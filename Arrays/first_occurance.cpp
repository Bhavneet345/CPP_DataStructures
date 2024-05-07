#include<iostream>
using namespace std;

int firstOccurance(int *arr, int start, int end, int num){
    int ans = -1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == num){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] > num){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n, num;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> num;
    cout << "first occurance is " << firstOccurance(arr, 0, n - 1, num);
    return 0;
}