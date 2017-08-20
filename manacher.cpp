#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ManacherString(string str) {
	string resStr = "#";
	for (int i = 0; i < str.size(); ++i)
		resStr = resStr + str[i] + "#";
	return resStr;
}

int Manacher(string str) {
	if (str.size() == 0) return 0;
	string manacher_str = ManacherString(str);
	vector<int> arr(manacher_str.size(), 1);//arr[i]记录以manacher_str[i]为中心的回文串的回文半径
	int maxLen = 0xffffffff;//记录最长的回文半径
	int C = 0, R = -1; //C是回文中心，R是回文右边界
	for (int i = 0; i < manacher_str.size(); ++i) {
		arr[i] = R > i ? min(arr[2*C - i], R-i) : 1;
		while(i + arr[i] < manacher_str.size() && i - arr[i] >= 0) {
			if (manacher_str[i + arr[i]] == manacher_str[i - arr[i]])
				++arr[i];
			else
				break;
		}

		if (i + arr[i] > R) {
			R = i + arr[i];
			C = i;
		}
		maxLen = max(maxLen, arr[i]);
	}
	return maxLen - 1;
}