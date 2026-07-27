class Solution {
public:
    int largestInteger(int n, int s) {
        int lim=pow(10,n)-1;
        int maxi=INT_MIN;
        for(int i=0; i<=lim; i++){
            int num=i;
            int sum=0;
            while(num > 0){
                int d=num%10;
                num=num/10;
                sum+=d;
            }
            if(sum == s) maxi=max(maxi,i);
        }
        if(maxi != INT_MIN) return maxi;
        return -1;
    }
};