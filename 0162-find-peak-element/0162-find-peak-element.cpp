class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;

        //first and last element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int s=1;
        int e=n-2;
        while(s <= e){
            int mid=(s+e)/2;
            //check if mid is the peak
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            //upward slope
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                s=mid+1; //aage hai peak
            }
            //downward slope
            else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                e=mid-1; //peeche hai peak
            }else{
                s=mid+1; //valley case
                //e=mid-1 also works, move either side
            }
        }

        return -1;
    }
};