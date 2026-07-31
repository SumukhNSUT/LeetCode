class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            v[word[i]-'a']++;
        }
        sort(v.rbegin(), v.rend());

        // i-6  c-2  g-2
        // a-2  d-2  h-2
        // b-2  e-2

        //main kaam
        int ans=0;
        for(int i=0; i<v.size(); i++){
            //top 8 most frequent
            if(i>=0 && i<=7){
                ans+=v[i];
            }
            else if(i>=8 && i<=15){
                ans+=2*v[i];
            }
            else if(i>=16 && i<=23){
                ans+=3*v[i];
            }
            else{
                //for i=24,25
                ans+=4*v[i];
            }
        }
        return ans;
    }
};