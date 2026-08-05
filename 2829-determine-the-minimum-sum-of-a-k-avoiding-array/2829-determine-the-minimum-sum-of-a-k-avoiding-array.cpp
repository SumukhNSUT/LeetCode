class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> s;
        int cnt=0;
        int sum=0;
        int num=1;
        while(cnt < n){
            if(!s.count(num)){
                sum+=num;
                if((k-num)!=num) s.insert(k-num);
                cnt++;
                num++;
            }else{
                num++;
            }
        }
        return sum;
    }
};