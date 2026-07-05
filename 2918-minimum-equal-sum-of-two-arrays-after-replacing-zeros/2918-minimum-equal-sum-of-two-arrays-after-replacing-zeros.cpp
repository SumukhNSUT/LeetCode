class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        long long s1=0; long long c1=0;
        long long s2=0; long long c2=0;
        for(auto it: nums1){
            s1+=it;
            if(it==0) c1++;
        }
        for(auto it: nums2){
            s2+=it;
            if(it==0) c2++;
        }

        if(c2==0){
            if(s1+c1>s2) return -1;
        }
        if(c1==0){
            if(s2+c2>s1) return -1;
        }
        if(s1 < s2){
            ans=max(s2+c2, s1+c1);
        }else if (s1>s2){
            ans=max(s1+c1, s2+c2);
        }else{
            //s1=s2
            if(c1>=c2) return s1+c1;
            else return s2+c2;
        }
        return ans;
    }
};

// s1=159, c1=10
// s2=161, c2=2