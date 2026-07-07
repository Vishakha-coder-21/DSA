class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        int p = 1;

        while (n) {
            int d = n % 10;
            if (d) {
                x += 1LL * d * p;
                sum += d;
                p *= 10;
            }
            n /= 10;
        }

        return x * sum;
    }
};
