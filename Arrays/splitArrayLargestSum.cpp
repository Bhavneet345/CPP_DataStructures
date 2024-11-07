#include<iostream>
#include<vector>
using namespace std;

int canSplit(vector<int>& nums, int k, int largetPossible){
    int subarray = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum > largetPossible){
            subarray += 1;
        }
    }
    return subarray + 1 <= k;
}

int splitArray(vector<int>& nums, int k){
    if(nums.size() == 1){
        return nums[0];
    }
    // start is the max of all the elements and end can be the sum of all the elements(subarray of all the elements)
    int start = INT_MIN, end = 0;
    for(int i = 0; i < nums.size(); i++){
        if(start < nums[i]){
            start = nums[i];
        }
        end += nums[i];
    }
    int ans = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        // a function to check if with the given sum it can split the array in required number of sub-arrays
        if(canSplit(nums, k, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}