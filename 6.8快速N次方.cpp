class QuickPower {
public:
    int getPower(int k, int N) {
        // write code here
       long long i = k, res = 1;
       while (N) {
           if (N & 1) res *= i;
           N = N >> 1;
           i = i * i % 1000000007;
           res = res % 1000000007;
       }
       return (int)res;
    }
};
