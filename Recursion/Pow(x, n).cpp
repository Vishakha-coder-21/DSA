class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        if (N == 0) return 1;

        double half = myPow(x, N / 2);

        return N % 2 ? half * half * x : half * half;
    }
};
