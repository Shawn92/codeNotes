class RadixSort {
public:
    int* radixSort(int* A, int n) {
        int max = 0;
        //先找到最大值
        for (int i = 0; i < n; ++i)
            max = A[i] > max ? A[i] : max;

        //从个位数开始依次执行入桶和出桶操作
        for (int i = 1; i < max; i *= 10) {
            //定义10个桶 0,1,...,9
            vector<vector<int>> bucket(10);

            //入桶
            for (int j = 0; j < n; ++j)
                bucket[A[j] / i % 10].push_back(A[j]);

            //出桶
            vector<int> temp;
            for (auto itA : bucket)
                for (auto itB : itA)
                    temp.push_back(itB);

            for (int i = 0; i < n; ++i)
                A[i] = temp[i];
        }
        return A;
    }
};