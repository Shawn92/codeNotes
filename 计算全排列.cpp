void Permutation(string str, int curPos, vector<string>& res) {
	if (curPos == str.size() - 1) {
		res.push_back(str);
		return;
	}
	for (int i = curPos; i < str.size(); ++i) {
		swap(str[curPos], str[i]);
		Permutation(str, curPos + 1, res);
		swap(str[curPos], str[i]);
	}
}

vector<string> Permutation(string str) {
	vector<string> res;//存放所有组合
	Permutation(str, 0, res);
	return res;
}