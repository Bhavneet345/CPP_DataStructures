#include<iostream>
#include<vector>
using namespace std;

vector<int> topoSort(vector<int> adj[], int n){
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++){
        for(auto nei: adj[i]){
            indegree[nei]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int front = q.front();
        res.push_back(front);
        q.pop();
        for(auto nei: adj[front]){
            indegree[nei]--;
            if(indegree[nei] == 0){
                q.push(nei);
            }
        }
    }
    return res;
}

string findOrder(string dict[], int n, int k){
    vector<int> adj[k];
    for(int i = 0; i < n - 1; i++){
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i]){
                adj['a' - s1[i]].push_back('a' - s2[i]);
                break;
            }
        }
    }
    vector<int> temp = topoSort(adj, n);
    string res = "";
    for(auto it: temp){
        res += char(it + 'a');
    }
    return res;
}