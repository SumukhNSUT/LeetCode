class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //last negative index nikaal lo
        int n=nums.size();
        int s=0;
        int e=n-1;
        int idx=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid] >= 0){
                e=mid-1;
            }else if(nums[mid] < 0){
                idx=mid;
                s=mid+1;
            }
        }
        //start of positives
        int j=-1;
        s=0;
        e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]<=0) s=mid+1;
            else if(nums[mid] > 0){
                j=mid;
                e=mid-1;
            }
        }
        cout << idx << " " << j << endl;
        int negs=idx-0+1;
        int pos=n-1-j+1;
        if(idx==-1 && j==-1) return 0;
        if(idx==-1) negs=0;
        if(j==-1) pos=0;
        return max(negs,pos);
    }
};