#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;


//求直方图包含的最大矩形的面积
int cal_maxArea(vector<int> arr) {
	stack<int> s; //记录一个严格递增序列
	int maxArea = 0;
	for (int i = 0; i < arr.size(); ++i) {
		while (!s.empty() && arr[i] <= arr[s.top()]) {
			int j = s.top();// 每弹出一个j，就要计算第j列扩展出的矩形的大小
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (i - k - 1) * arr[j];//第j列的高度为arr[j]，左起当前的栈顶(s.top())即k + 1，右达i - 1，所以总长度为i-k-1
			maxArea = max(maxArea, curArea);
		}
		s.push(i);
	}
	//数组读完了，栈中还有变量，全部执行弹出操作，并计算面积
	while (!s.empty()) {
		int j = s.top();
		s.pop();
		int k = s.empty() ? -1 : s.top();
		int curArea = (arr.size() - 1 - k) * arr[j];
		maxArea = max(maxArea, curArea);
	}
	return maxArea;
}

int cal(vector<vector<int>> arr) {
	int maxArea = 0;
	vector<int> height(arr[0].size(), 0);
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j)
			height[j] = arr[i][j] == 0 ? 0 : height[j] + 1;
		maxArea = max(maxArea, cal_maxArea(height));
	}
	return maxArea;
}


int main(int argc, const char* argv[]) {

	vector<vector<int>> arr{
					 {1, 0, 1, 1},
					 {1, 1, 1, 1},
					 {1, 1, 1, 0} };
	cout << cal(arr) << endl;
	getchar();
	return 0;
}