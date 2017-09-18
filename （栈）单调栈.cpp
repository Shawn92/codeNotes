void DanDiaoStack(vector<int> const& arr, vector<int>& leftMax, vector<int>& rightMax) {
	stack<int> s;
	for (int i = 0; i < arr.size(); ++i) {
		while (!s.empty() && arr[i] > arr[s.top()]) {
				rightMax[s.top()] = arr[i];
				s.pop();
		}
		if (s.empty()) {
			leftMax[i] = -1;
			s.push(i);
		}
		else {
			leftMax[i] = arr[s.top()];
			s.push(i);
		}
	}

	while (!s.empty()) {
		rightMax[s.top()] = -1;
		s.pop();
	}
}