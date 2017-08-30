class HeapSort {
public:
    int* heapSort(int* A, int n) {
        BuildHeap(A, n);
        for (int i = n - 1; i > 0; --i) {
            int temp = A[i];
            A[i] = A[0];
            A[0] = temp;
            MaxHeapify(A, 0, i);
        }
        return A;
    }
    
    void MaxHeapify(int* A, int i, int n) {
        int leftChild = 2*i + 1, rightChild = 2*i + 2, min = i;
        if (leftChild < n && A[leftChild] >= A[min])
            min = leftChild;
        if (rightChild < n && A[rightChild] >= A[min])
            min = rightChild;
        if (min != i) {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
	        MaxHeapify(A, min, n);
        }
    }
    
    void BuildHeap(int* A, int n) {
        int p = n / 2 - 1;
        for (int i = p; i >= 0; --i)
            MaxHeapify(A, i, n);
    }
};