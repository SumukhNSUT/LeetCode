class Solution {
    int fn(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d*d;
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        while(n!=1 && n!=4){
            int sum=fn(n); //sum of squares of digits
            if(sum==1) return true;
            n=sum;
        }
        return false;
    }
};