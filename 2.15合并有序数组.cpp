class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        int j = n - 1;
        int k = m - 1;
        for (int i = m + n - 1; i >= 0; --i) {
            if (A[j] > B[k])
                A[i] = A[j--];
            else
                A[i] = B[k--];
        }
        return A;
    }

};