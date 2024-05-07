#include<iostream>
using namespace std;

void merge2Sorted(int *arr1, int *arr2, int n, int m){
    int k = (n + m) - 1;
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            arr1[k] = arr1[i];
            i--;
            k--;
        } 
        else{
            arr1[k] = arr2[j];
            k--;
            j--;
        }
    }
    while(j >= 0){
        arr1[i] = arr2[j];
        i--;
        j--;
    }
    return;
}