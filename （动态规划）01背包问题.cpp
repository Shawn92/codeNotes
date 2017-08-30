class Backpack {
public:
    int maxValue(vector<int> w, vector<int> v, int n, int cap) {
        // write code here
        vector<int> dp(cap + 1, 0);
        for (int i = 0; i < n; ++i) 
            for (int j = cap; j > 0; --j) 
                if (w[i] <= j)
                    dp[j] = max(dp[j-w[i]] + v[i], dp[j]);
        return dp[cap];
    }
};