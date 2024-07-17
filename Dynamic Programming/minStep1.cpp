#include<iostream>
#include<climits>
using namespace std;

int returnStepstoOne(int n)
{
   if(n == 1)
   {
       return 0;
   }
   if(n <= 3)
   {
       return 1;
   }
   int a = returnStepstoOne(n - 1), b = INT_MAX, c = INT_MAX;
   if(n % 2 == 0)
   {
       b = returnStepstoOne(n / 2);
   }
   if(n % 3 == 0)
   {
       c = returnStepstoOne(n / 3);
   }
   return min(a, min(b, c)) + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << returnStepstoOne(n);
    return 0;
}