class MergeSort {
public:
    void merge(int *A, int left, int mid, int right) {
        int *mergedA = (int*)malloc((right - left + 1) * sizeof(int));
        int l = left, r = mid + 1;
        int i = 0;
        while (l <= mid && r <= right) {
            if (A[l] < A[r])
                mergedA[i++] = A[l++];
            else
                mergedA[i++] = A[r++];
        }
        while (l <= mid)
            mergedA[i++] = A[l++];
        while (r <= right)
            mergedA[i++] = A[r++];
        for (int i = 0; i < right - left + 1; ++i)
            A[left + i] = mergedA[i];
    }

    void mergeSortA(int *A, int left, int right) {
        if (right - left < 1)
            return;
        int mid = (left + right) / 2;
        mergeSortA(A, left, mid);
        mergeSortA(A, mid + 1, right);
        merge(A, left, mid, right);
    }

    int* mergeSort(int* A, int n) {
        if (n <= 1)
            return A;
        mergeSortA(A, 0, n - 1);
        return A;
    }
};