class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 1; j < n - i; ++j) {
                if (A[j-1] > A[j]) {
                    A[j-1] = A[j-1] + A[j];
                    A[j] = A[j-1] - A[j];
                    A[j-1] = A[j-1] - A[j];
                }
            }
        }
        return A;
    }
};