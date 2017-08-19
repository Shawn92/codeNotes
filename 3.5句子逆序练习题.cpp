class Reverse {
public:
    string reverseSentence(string A, int n) {
        // write code here
        reverse(A.begin(), A.end());
        int i, j;
        for (i = 0, j = 0; i < n; ++i) {
            if (A[i] == ' ') {
                reverse(A.begin() + j, A.begin() + i);
                j = i + 1;
            }
        }
        if (j > 0)
            reverse(A.begin() + j, A.end());
        return A;
    }
};