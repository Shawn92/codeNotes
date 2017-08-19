class Checker {
public:
	void MaxHeapify(vector<int>& maxHeap, int i, int n) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		while (left < n) {
			int min = i;
			if (left < n && maxHeap[min] < maxHeap[left])
				min = left;
			if (right < n && maxHeap[min] < maxHeap[right])
				min = right;
			if (min != i) {
				swap(maxHeap[i], maxHeap[min]);
				i = min;
				left = 2 * i + 1;
				right = 2 * i + 2;
			}
			else
				break;
		}
	}

	void BuildHeap(vector<int>& arr, int size) {
		int p = size / 2 - 1; // 最后一个叶子节点的父亲节点
		for (int i = p; i >= 0; --i)
			MaxHeapify(arr, i, size);
	}

	void heapSort(vector<int>& arr, int n) {
		BuildHeap(arr, n);
		for (int i = n - 1; i >= 0; --i) {
			swap(arr[i], arr[0]);
			MaxHeapify(arr, 0, i);
		}
	}

	bool checkDuplicate(vector<int> a, int n) {
		heapSort(a, n);
		for (int i = 1; i < n; ++i)
			if (a[i] == a[i - 1])
				return true;
		return false;
	}
};