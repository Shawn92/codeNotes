void HannoTowwer(int n, string from, string by, string to) {
	if (n == 1) {
		cout << "将1个棋子从" << from << "移动到" << to << endl;
		return;
	}
	else {
		HannoTowwer(n - 1, from, to, by);
		cout << "将1个棋子从" << from << "移动到" << to << endl;
		HannoTowwer(n - 1, by, from, to);
	}
}