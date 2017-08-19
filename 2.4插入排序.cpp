class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        int i, j;
        for (i = 1; i < n; ++i) {
            for (j = i; j > 0 && A[j - 1] > A[j]; --j) {
                swap(A[j], A[j - 1]);
            }
        }
        return A;
    }
};