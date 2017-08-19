class Prior {
public:
    static bool comStr(const string& A, const string& B) {
        return (A + B) < (B + A);
    }
    
    string findSmallest(vector<string> strs, int n) {
        // write code here
        sort(strs.begin(), strs.end(), comStr);
        string str = "";
        for (auto item : strs)
            str += item;
        return str;
    }
};