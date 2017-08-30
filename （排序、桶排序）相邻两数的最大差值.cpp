class Gap {
public:
    int maxGap(vector<int> A, int n) {
        // write code here
        if (n < 2)
            return 0;
        int min = 0x7fffffff, max = 0xffffffff;
        for (int i = 0; i < n; ++i) {
            if (min > A[i]) min = A[i];
            if (max < A[i]) max = A[i];
        }
  
        double gap = double(max - min) / double(n);
        vector<vector<int>> bucket(n + 1);
        for (int i = 0; i < n; ++i) {
            int j = (A[i] - min) / gap;
            bucket[j].push_back(A[i]);
        }
  
        int maxGap = 0xffffffff;
        int i = 0;
        while (i < n) {
            //若是空桶则继续循环
            if (bucket[i].size() == 0) {
                ++i;
                continue;
            }
            //不是空桶则找下一个非空桶next
            int next = i + 1;
            while (bucket[next].size() == 0 && next < n + 1)
                ++next;
            int temp = *min_element(bucket[next].begin(), bucket[next].end()) - *max_element(bucket[i].begin(), bucket[i].end());
            maxGap = temp > maxGap ? temp : maxGap;
            i = next;
        }
        return maxGap;
    }
};