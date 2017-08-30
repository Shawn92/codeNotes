class ShellSort {
public:
    int* shellSort(int* A, int n) {
        int i, j, gap;
        for (gap = n / 2; gap > 0; gap /= 2) {
            for (i = gap; i < n; ++i) {
                for (j = i - gap; j >= 0 && A[j] > A[j + gap]; j -= gap) {
                    swap(A[j], A[j + gap]);
                }
            }
        }
        return A;
    }
};