class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;

        long long p1=n/2;
        long long ans1=(long long)s + p1*m - max(0LL,p1-1);
        long long p2=(n-1)/2;
        long long ans2=1LL*s + p2*(m-1);
        return max(ans1,ans2);
    }
};