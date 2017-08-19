class LongestIncreasingSubsequence {
public:
	int getLIS(vector<int> A, int n) {
	// write code here
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		int max = 0;
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i])
				max = dp[j] >= max ? dp[j] : max;
		}
		dp[i] = max + 1;
	}
	return *max_element(dp.begin(), dp.end());
}
};