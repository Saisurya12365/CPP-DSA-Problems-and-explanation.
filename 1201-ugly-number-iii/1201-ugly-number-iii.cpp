class Solution {
    #define int long long
    int __gcd(int a, int b) {
        if(b == 0) return a;
        return __gcd(b, a % b);
    }
    int lcm(int a, int b) {
        if (a == 0 || b == 0) return 0;
        int m = a / __gcd(a, b);
        if (m > 2000000001 / b) return 2000000001;
        return m * b;
    }
    int lcm(int a, int b, int c) {
        return lcm(lcm(a, b), c);
    }
    #undef int
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        #define int long long
        auto find = [&](int t) {
            int ab = lcm(a,b),bc = lcm(b,c),ca = lcm(c,a);
            int abc = lcm(a,b,c);
            int x = t/a + t/b + t/c - t/ab - t/bc - t/ca + t/abc;
            return x;
        };
        int lo = 0, hi = 2e9;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(find(mid) >= n) {
                ans = mid;
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
        #undef int
        return ans;
    }
};