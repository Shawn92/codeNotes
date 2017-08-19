class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
        // write code here
        int e0 = 0, e1 = 0;
        for (auto item : arr)
            e0 ^= item;
        int k = e0 & (~e0 + 1);//得到最右边的1
        
        for (auto item : arr)
            if (item & k)
                e1 ^= item;
        
        vector<int> res;
        res.push_back(e1);
        res.push_back(e0 ^ e1);
        sort(res.begin(), res.end());
        return res;
    }
};