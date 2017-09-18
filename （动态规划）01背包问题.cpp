一个背包有一定的承重cap，有N件物品，每件都有自己的价值，记录在数组v中，也都有自己的重量，记录在数组w中，每件物品只能选择要装入背包还是不装入背包，要求在不超过背包承重的前提下，选出物品的总价值最大。

给定物品的重量w价值v及物品数n和承重cap。请返回最大总价值。

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