#include<iostream>
#include<vector>
using namespace std;

int calcSum(vector<vector<int> > arr, int row, int col){
    int sum = 0;
    for(int i = col; i < col + 3; i++){
        sum += arr[row][i];
        sum += arr[row + 2][i];
    }
    sum += arr[row + 1][col + 1];
    return sum;
}

int hourglassSum(vector<vector<int> > arr){
    int maximum = INT_MIN;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int sum = calcSum(arr, i, j);
            if(maximum < sum){
                maximum = sum;
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    return maximum;
}

int main(){
    vector<vector<int> >arr(6, vector<int>(6));
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }
    cout << hourglassSum(arr);
    return 0;
}