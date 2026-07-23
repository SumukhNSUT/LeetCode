class Solution {
    bool fn(int num){
        int temp=num;
        while(temp > 0){
            int d=temp%10;
            if(d==0) return false;
            if(d !=0 && num%d != 0) return false;
            temp=temp/10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++){
            if(fn(i)) ans.push_back(i);
        }
        return ans;
    }
};