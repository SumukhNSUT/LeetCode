class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        long long m=1e9+7;
        set<long long>c;
        c.insert(2);
        vector<int>r=nums;
        for(int x:r){
            int v=x;
            for(int d=2; d*d<=v; d++){
                if(v%d==0){
                    c.insert(d);
                    while(v%d==0){
                        v/=d;
                    }
                }
            }
            if(v>1){
                c.insert(v);
            }
        }
        long long p=-2e18;
        long long b=-1;
        for(long long k: c){
            long long y=-2e18;
            long long s=-2e18;
            for(int n: r){
                long long v=(n%k==0)?n:-n;
                s=max((long long)v, s+v);
                y=max(y,s);
            }
            if(y>p){
                p=y;
                b=k;
            }else if(y==p && k<b){
                b=k;
            }
        }
        long long a=(p%m)*(b%m);
        a%=m;
        if(a<0) a+=m;
        return a;
    }
};