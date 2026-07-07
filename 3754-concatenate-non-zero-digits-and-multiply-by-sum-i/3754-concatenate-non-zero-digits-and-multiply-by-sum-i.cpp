class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        while(n>0){
            int d=n%10;
            if(d!=0){
                sum+=d;
                num=num*10+d;
            }
            n=n/10;
        }
        //reverse num
        long long res=0;
        while(num>0){
            int d=num%10;
            res=res*10+d;
            num=num/10;
        }
        return (long long)res*sum;
    }
};