class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // rating high to low
        // same rating-> id high to low
        vector<pair<int,int>>ans;
        for(auto it: restaurants){
            int id=it[0];
            int rating=it[1];
            int veg=it[2];
            int price=it[3];
            int dist=it[4];

            if(( (veganFriendly==1 &&veg==1) || veganFriendly==0) && price<=maxPrice && dist<=maxDistance){
                ans.push_back({rating,id});
            }
        }
        
        sort(ans.begin(), ans.end(), [](auto &a, auto &b){
            if(a.first==b.first){
                return a.second>b.second;
            }

            return a.first > b.first;
        });
        vector<int> res;
        for(auto it: ans){
            res.push_back(it.second);
        }
        return res;
    }
};