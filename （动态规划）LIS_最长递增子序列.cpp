//LIS问题、最长递增子序列（非连续的）
class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) 
            for (int j = 0; j < i; ++j) 
                if (A[i] > A[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
        return *max_element(dp.begin(), dp.end());
    }
};
//LCS问题、最长公共子序列（非连续的）
class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (A[i-1] == B[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        return dp[n][m];
    }
};
//LSubStr问题、最长公共子串（连续的）
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxLen = 0xffffffff;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(dp[i][j], maxLen);
            }
        }
        return maxLen;
    }
};