#include<iostream>
#include<queue>
using namespace std;

int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i = 0; i < A.size(); i++){
        minheap.push(A[i]);
    }
    int result = 0;
    while(true){
        if(minheap.top() >= k){
            break;
        }
        int first = minheap.top();
        minheap.pop();
        if(minheap.empty()){
            return -1;
        }
        int second = minheap.top();
        minheap.pop();
        int res = first + (2 * second);
        minheap.push(res);
        ++result;
    }
    return result;
}

int main(){
    vector<int> input;
    int k, n;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    cout << cookies(k, input);
    return 0;
}
