#include <iostream>
#include <vector>
using namespace std;
int knapsackBottomUp(vector<int>& weight, vector<int>& value, int W) {
   int N = weight.size();
   vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
   for (int i = 1; i <= N; ++i) {
       for (int w = 1; w <= W; ++w) {
           if (weight[i - 1] <= w)
               dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
           else
               dp[i][w] = dp[i - 1][w];
       }
   }
   return dp[N][W];
}
