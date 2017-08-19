class CountingSort {
public:
    int* countingSort(int* A, int n) {
        
        int i, j, max = 0;
        //先找到最大元素
        for (i = 0; i < n; ++i)
            max = A[i] > max ? A[i] : max;
        
        int* C = (int*)malloc((max+1)*sizeof(int));
        for (i = 0; i <= max; ++i)
            C[i] = 0;
        //C[i]的值为等于i的个数
        for (i = 0; i < n; ++i)
            ++C[A[i]];
        //C[i]的值为小于等于i的个数
        for (i = 1; i <= max; ++i)
            C[i] += C[i - 1];
        
        int *B = (int*)malloc(n*sizeof(int));
        for (i = n - 1; i >= 0; --i) {
            B[C[A[i]] - 1] = A[i];
        	--C[A[i]];
        }
        
        return B;
    }
};