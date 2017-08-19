class QuickSort {
public:
    int* quickSort(int* A, int n) {
		quickSortA(A, 0, n - 1);
        return A;
    }
    
    void quickSortA(int* A, int start, int end) {
        if(end - start < 1)
            return;
        int p = partition(A, start, end);
        quickSortA(A, start, p - 1);
        quickSortA(A, p + 1,end);
    }
    
    int partition(int *A, int start, int end) {
        int key = A[start];
        int l = start, r = end;
        while (l < r) {
            while (r > l && A[r] >= key) --r;
            A[l] = A[r];
            while (r > l && A[l] < key) ++l;
            A[r] = A[l];
        }
        A[l] = key;
        return l;
    }
};