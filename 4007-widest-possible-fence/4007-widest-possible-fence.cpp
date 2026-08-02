class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        sort(planks.begin(), planks.end());
        map<int,int> mpp;
        for (int i=0; i<n; i++){
            mpp[planks[i]]++;
        }
        vector<pair<int,int>> v;
        for (auto [a,b] : mpp){
            v.push_back({a, b});
        }
        map<int,int> heights;
        int maxi = 1;
        for (int i=0; i<v.size(); i++){
            auto [h, freq] = v[i];
            heights[h] += freq;
            heights[h+h] += freq/2;
            maxi = max(maxi, heights[h]);
            maxi = max(maxi, heights[h+h]);
            for (int j=i+1; j<v.size(); j++){
                auto [h2, freq2] = v[j];
                int curh = h + h2;
                heights[curh] += min(freq, freq2);
                maxi = max(maxi, heights[curh]);
            }
        }
        return maxi;
    }
};