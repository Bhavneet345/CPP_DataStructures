#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, greater<int>>temp;
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++){
        int type;
        cin >> type;
        if(type == 1){
            int data;
            cin >> data;
            minheap.push(data);
        }
        else if(type == 2){
            int data;
            cin >> data;
            while(!minheap.empty()){
                if(data == minheap.top()){
                    minheap.pop();
                    continue;
                }
                temp.push(minheap.top());
                minheap.pop();
            }
            minheap.swap(temp);
        }
        else {
            cout << minheap.top() << endl;
        }
    }
    return 0;
}