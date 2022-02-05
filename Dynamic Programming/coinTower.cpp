#include<iostream>
using namespace std;

string findWinner(int x, int y, int n)
{
   int *dp = new int[n + 1];
   dp[0] = 0;
   dp[1] = 1;
   for(int i = 2; i <= n; i++)
   {
       dp[i] = 0;
       if(i - y >= 0 && !dp[i - y])
       {
           dp[i] = 1;
       }
       if(i - x >= 0 && !dp[i - x])
       {
           dp[i] = 1;
       }
       if(i - 1 >= 0 && !dp[i - 1])
       {
           dp[i] = 1;
       }
   }
   if(dp[n] == 1)
   {
       return "Beerus";
   }
   return "Wise";
}

int main()
{
    int x, y, n;
    cin >> n >> x >> y;
    cout << findWinner(x, y, n);
    return 0;
}
