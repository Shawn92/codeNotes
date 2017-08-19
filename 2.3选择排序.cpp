class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        for (int i = 0; i < n - 1; ++i) {
			int min_pos = i; //记录最小元素的位置
			for (int j = i + 1; j < n; ++j) {
				if (A[j] < A[min_pos])
					min_pos = j;
			}
			int temp = A[i];
			A[i] = A[min_pos];
			A[min_pos] = temp;
		}
		return A;
    }
};