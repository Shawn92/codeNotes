#define MAX 100000
bool prime[MAX];
void isPrime(int max) {
	memset(prime, 1, MAX);
	prime[0] = prime[1] = 0;
	prime[2] = 1;
	for (int i = 2; i <= max; i += 2)//先把偶数都筛掉
		prime[i] = 0;
    for(int i=3;i<=t;i++)//现在只处理奇数的情况
        if(prime[i])
            for(int j = i*i;j <= Max;j += 2*i)//优化每次都增长偶数长度 
                prime[j]=0;
}
