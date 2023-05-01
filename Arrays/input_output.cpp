#include<iostream>
using namespace std;

int main()
{
    int arr[20], n;
    cin>>n;
    cout<<"Enter the elements\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<"Elements are as follows\n";

    for(int i = 0; arr[i] != '\0'; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}