class Translation {
public:
    string stringTranslation(string A, int n, int len) {
        // write code here
        reverse(A.begin(), A.begin() + len);
        reverse(A.begin() + len, A.end());
        reverse(A.begin(), A.end());
        return A;
    }
};