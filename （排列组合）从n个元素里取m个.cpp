//arr  :  元素数组
//当前需要从前curLen个元素里取m个
//调用方法为 combine(arr, 3, arr.size(), temp, res);
void combine(vector<int> arr, int m, int curLen, vector<int>& temp, vector<vector<int>>& res) {
	if (m == 0) {
		res.push_back(temp);
		return;
	}
	for (int i = curLen - 1; i >= m-1; --i) {
		temp.push_back(arr[i]);//选定arr[i]
		combine(arr, m - 1, i, temp, res);//从前arr[0]到arr[i-1]个里取m-1个
		temp.erase(temp.end() - 1);//回溯，从temp的末尾移除arr[i]
	}
}