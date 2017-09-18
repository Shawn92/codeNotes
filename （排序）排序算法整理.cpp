void bubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 1; j < arr.size() - i; ++j)
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
}

void selectSort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); ++i) {
		int min_pos = i;
		for (int j = i + 1; j < arr.size(); ++j)
			if (arr[j] < arr[min_pos])
				min_pos = j;
		swap(arr[i], arr[min_pos]);
	}
}

void insertSort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); ++i)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
			swap(arr[j - 1], arr[j]);
}

void shellSot(vector<int>& arr) {
	for (int gap = arr.size() / 2; gap > 0; gap /= 2)
		for (int i = gap; i < arr.size(); ++i)
			for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap)
				swap(arr[j - gap], arr[j]);
}

void merge(vector<int>& arr, int left, int mid, int right) {
	vector<int> tempArr;
	int l = left, r = mid + 1;
	while (l <= mid && r <= right) {
		if (arr[l] < arr[r])
			tempArr.push_back(arr[l++]);
		else
			tempArr.push_back(arr[r++]);
	}
	while (l <= mid)
		tempArr.push_back(arr[l++]);
	while (r <= right)
		tempArr.push_back(arr[r++]);
	for (int i = 0; i < tempArr.size(); ++i)
		arr[i + left] = tempArr[i];
}

void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

//nth_element

int partition(vector<int>& arr, int left, int right) {
	int key = arr[left], l = left, r = right;
	while (l < r) {
		while (l < r && arr[r] >= key) --r;
		swap(arr[l], arr[r]);

		while (l < r && arr[l] <= key) ++l;
		swap(arr[l], arr[r]);
	}
	arr[l] = key;
	return l;
}

int partition2(vector<int>& arr, int left, int right) {
	int key = arr[left], l = left, r = right;
	while (l < r) {
		while (l < r && arr[r] >= key) --r;
		while (l < r && arr[l] <= key) ++l;
		if (l < r) 
			swap(arr[r--], arr[l++]);
	}
	swap(arr[left], arr[r]);
	return l;
}

void quickSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int p = partition2(arr, left, right);
		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
}

void maxHeapify(vector<int>& arr, int i, int n) {
	int left = 2 * i + 1, right = 2 * i + 2, min = i;
	if (left < n && arr[left] > arr[min])
		min = left;
	if (right < n && arr[right] > arr[min])
		min = right;
	if (min != i) {
		swap(arr[i], arr[min]);
		maxHeapify(arr, min, n);
	}
}

void buildHeap(vector<int>& arr, int n) {
	for (int i = (n / 2) - 1; i > -0; --i)
		maxHeapify(arr, i, n);
}

void heapSort(vector<int>& arr, int n) {
	buildHeap(arr, n);
	for (int i = n - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, 0, i);
	}
}

void countSort(vector<int>& arr) {
	int maxEle = *max_element(arr.begin(), arr.end());
	vector<int> C(maxEle + 1, 0);
	for (int i = 0; i < arr.size(); ++i)
		++C[arr[i]];
	for (int i = 1; i < C.size(); ++i)
		C[i] += C[i - 1];
	vector<int> B(arr.size());
	for (int i = arr.size() - 1; i >= 0; --i) {
		B[C[arr[i]] - 1] = arr[i];
		--C[arr[i]];
	}
	arr = B;
}

void radixSort(vector<int>& arr) {
	int maxEle = *max_element(arr.begin(), arr.end());
	for (int i = 1; i < maxEle; i *= 10) {
		vector<vector<int>> bucket(10);
		//装桶操作
		for (auto item : arr)
			bucket[item / i % 10].push_back(item);
		//出桶操作
		int j = 0;
		for (auto it1 : bucket)
			for (auto it2 : it1)
				arr[j++] = it2;
	}
}