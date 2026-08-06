class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int num=n; num<=1e9; num++){
            int p=1;
            int temp=num;
            if(temp == 0) p=0;
            while(temp > 0){
                int d=temp%10;
                p*=d;
                temp=temp/10;
            }
            if(p%t==0) return num;
        }
        return -1;
    }
};