#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> >minheap;
    priority_queue<int, vector<int>, greater<int> >temp;
    minheap.push(1);
    minheap.push(2);
    minheap.push(3);
    while(!minheap.empty()){
        if(minheap.top() == 2){
            minheap.pop();
            continue;
        }
        temp.push(minheap.top());
        minheap.pop();
    }
    minheap.swap(temp);
    cout << temp.size() << endl;
    while(!minheap.empty()){
        cout << minheap.top() << " ";
        minheap.pop();
    }
    return 0;
}