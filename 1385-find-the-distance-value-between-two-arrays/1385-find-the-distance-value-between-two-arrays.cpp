class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(auto it: arr1){
            bool ok=true;
            for(int i=0; i<arr2.size(); i++){
                if(abs(it-arr2[i]) <= d){
                    ok=false;
                    break;
                }
            }

            if(ok) cnt++;
        }
        return cnt;
    }
};