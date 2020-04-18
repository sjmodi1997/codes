class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==1 || n==0)
            return 0;
        k = min(k,n);
        if ( k >= n/2 )
        {
            int profit = 0; 
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i-1] )
                {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit; 
        }
    
        int dp[k+1][n+1];
        for(int i=1;i<=k;i++)
        {
            dp[i][0] = 0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[0][j] = 0;
        }
        for(int t=1;t<=k;t++)
        {
            for(int j=1;j<n;j++)
            {
                int tmpMax = INT_MIN;
                for(int m=0;m<j;m++)
                {
                    tmpMax = max(tmpMax,prices[j]-prices[m]+dp[t-1][m]);
                }
                dp[t][j] = max(dp[t][j-1],tmpMax);
            }
        }
        return dp[k][n-1];
    }
};
