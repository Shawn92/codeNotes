class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        // write code here
        if (lena != lenb) return false;
        map<char, int> chMap;
        for (int i = 0; i < lena; ++i) {
            if (chMap.find(A[i]) == chMap.end())
                chMap.insert(pair<char, int>(A[i], 1));
            else
                ++chMap[A[i]];
        }
        
        for (int i = 0; i < lenb; ++i) {
            if (chMap.find(B[i]) == chMap.end())
                return false;
            else
                --chMap[B[i]];
        }
        
        for (auto it : chMap) {
            if (it.second != 0)
                return false;
        }
        
        return true;
    }
};