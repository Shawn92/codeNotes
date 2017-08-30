class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        // write code here
        int dp[n][aim+1];
        //第一行
        for (int i = 0; i < aim + 1; ++i) {
            if (i % penny[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }
        //第一列
        for (int i = 0; i < n; ++i)
            dp[i][0] = 1;//如果是最少的钱数，这里应该设置成0

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < aim + 1; ++j) {
                dp[i][j] = 0;
                for (int k = 0; k * penny[i] <= j; ++k)
                    dp[i][j] += dp[i - 1][j - k*penny[i]];
            }
        }
        
        return dp[n - 1][aim];
    }
};