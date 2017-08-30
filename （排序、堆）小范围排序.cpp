知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。
给定一个int数组A，同时给定A的大小n和题意中的k，请返回排序后的数组。
测试样例：
[2,1,4,3,6,5,8,7,10,9],10,2
返回：[1,2,3,4,5,6,7,8,9,10]



class ScaleSort {
public:
    //保持以i为根节点的最小堆的最小性，n为堆中的元素个数
	void MinHeapify(vector<int>& minHeap, int i, int n) {
		int left = 2*i + 1;
		int right = 2*i + 2;
		int min = i;
		if (left < n && minHeap[left] < minHeap[min])
			min = left;
		if (right < n && minHeap[right] < minHeap[min])
			min = right;
		if (min != i) {
			swap(minHeap[i], minHeap[min]);
			MinHeapify(minHeap, min, n);
		}
	}
    
	//建堆函数，将数组minHeap最小堆化
	void BuildHeap(vector<int>& minHeap) {
		int p = minHeap.size() / 2;
		for (int i = p - 1; i >= 0; --i)
			MinHeapify(minHeap, i, minHeap.size());
	}

	vector<int> sortElement(vector<int> A, int n, int k) {
		vector<int> minHeap(A.begin(), A.begin() + k);
		BuildHeap(minHeap);
		vector<int> res;
		//处理0-(n-k)范围内的数
		for (int i = k; i < n; ++i) {
			A[i - k] = minHeap[0];
			minHeap[0] = A[i];
			MinHeapify(minHeap, 0, k);
		}
		//处理最后k个数
		int size_heap = minHeap.size();
		while (size_heap > 0) {
			A[n - size_heap] = minHeap[0];
			swap(minHeap[0], minHeap[size_heap-1]);
			MinHeapify(minHeap, 0, --size_heap);
		}
		return A;
	}
};