//加法
int add(int a, int b) {
	int sum = a;
	while (b) {
		sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return sum;
}

//减法
int sub(int a, int b) {
	return add(a, add(~b, 1));
}

//乘法
int multi(int a, int b) {
	int res = 0;
	while (b) {
		if (b & 1)
			res = add(res, a);
		a <<= 1;
		b = (b >> 1) & 0x7fffffff;
	}
	return res;
}