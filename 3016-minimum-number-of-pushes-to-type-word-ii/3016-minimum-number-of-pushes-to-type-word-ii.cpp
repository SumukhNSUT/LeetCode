class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int> mp;
        for(auto it: word) mp[it]++;

        vector<pair<int,char>>v;
        for(auto it: mp){
            v.push_back({it.second,it.first});
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
                ans+=v[i].first;
            }
            else if(i>=8 && i<=15){
                ans+=2*v[i].first;
            }
            else if(i>=16 && i<=23){
                ans+=3*v[i].first;
            }
            else{
                //for i=24,25
                ans+=4*v[i].first;
            }
        }
        return ans;
    }
};