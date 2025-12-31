#include<iostream>
#include<vector>
#include "disjointSets.h"
using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> map;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string mail = accounts[i][j];
            if(map.find(mail) == map.end()){
                // new email
                map[mail] = i;
            }
            else{
                // mail already exisits in different node so merger both of them
                ds.unionBySize(i, map[mail]);
            }
        }
    }
    // now we have a map that contains mail wrt to nodeNo/accountNo. therefore merge the mail with their ultimate parent
    // in a vector
    vector<string> merged[n];
    for(auto it: map){
        string mail = it.first;
        int node = ds.findUltimateParent(it.second);
        merged[node].push_back(mail);
    }
    // now in merged we have all the mails merged wrt to orignal parent account no we just have sort and place the name in front
    vector<vector<string>> result;
    for(int i = 0; i < n; i++){
        if(merged[i].size() == 0) continue;
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        sort(merged[i].begin(), merged[i].end());
        for(auto mails: merged[i]){
            temp.push_back(mails);
        }
        result.push_back(temp);
    }
    return result;
}