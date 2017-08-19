对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。

给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。保证A中字符全部为小写英文字符，且长度小于等于500。

测试样例：
"aabcb",5
返回：3

class DistinctSubstring {
public:
    int longestSubstring(string A, int n) {
        // write code here
        int l = 0, r = 0, max = 1;
        set<char> chSet;

        for (int r = 0; r < n; ++r) {
            if (chSet.find(A[r]) == chSet.end()) 
                chSet.insert(A[r]);
            else{
                for (; A[l] != A[r]; ++l)
                    chSet.erase(A[l]);
                ++l;
            }
            max = max >(r - l + 1) ? max : (r - l + 1);
            string s = string(A.begin() + l, A.begin() + r + 1);
        }
        return max;
    }
};
