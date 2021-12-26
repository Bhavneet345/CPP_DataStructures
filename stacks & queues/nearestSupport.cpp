#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmall(vector<int> arr, int n)
{
    stack<int> pending;
    vector<int> result(n);
    result[0] = -1;
    pending.push(arr[0]);
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] <= pending.top())
        {
            while(!pending.empty() && arr[i] <= pending.top())
            {
                pending.pop();
            }
            if(!pending.empty())
            {
                result[i] = pending.top();
            }
            else
            {
                result[i] = -1;
            }
        }
        else
        {
            result[i] = pending.top();
        }
        pending.push(arr[i]);
    }
    return result;
}

int main()
{
    int n, data;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        arr[i] = data;
    }
    vector <int> result = prevSmall(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
