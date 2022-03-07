#include<iostream>
#include<vector>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int> > queries){
    vector<vector<int> > arr(n);
    vector<int> ans;
    int totalQueries = queries.size();
    int lastans = 0;
    for(int i = 0; i < totalQueries; i++){
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = ((x ^ lastans) % n);
        if(queries[i][0] == 1){
            arr[idx].push_back(y);
        } 
        else{
            int pos = y % arr[idx].size();
            lastans = arr[idx][pos];
            ans.push_back(lastans);
        }
    }
    return ans;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int> > arr(q, vector<int>(3));
    for(int i = 0; i < q; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << endl;
    vector<int> ans = dynamicArray(n, arr);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}