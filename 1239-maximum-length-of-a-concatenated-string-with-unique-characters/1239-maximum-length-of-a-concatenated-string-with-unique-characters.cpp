class Solution {
    int fn(int idx, vector<string>& arr, unordered_map<char,int>& mp) {
        int n=arr.size();
        if(idx==n){
            return mp.size();
        }

        //not pick
        int npick=fn(idx+1,arr,mp);
        //pick
        bool ok=true;
        unordered_map<char,int> temp;
        for(auto ch : arr[idx]){
            temp[ch]++;

            if(temp[ch] > 1 || mp.count(ch)){
                ok=false;
                break;
            }
        }

        int pick = 0;
        if(ok){
            for(auto ch : arr[idx]){
                mp[ch]++;
            }

            pick = fn(idx + 1, arr, mp);
            //backtrack
            for(auto ch : arr[idx]){
                mp.erase(ch);
            }
        }

        return max(pick, npick);
    }

public:
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> mp;
        int n=arr.size();
        return fn(0, arr, mp);
    }
};