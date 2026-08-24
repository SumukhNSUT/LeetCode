class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q; //val,index
        int n=tickets.size();
        for(int i=0; i<n; i++){
            q.push({tickets[i],i});
        }
        int t=0;
        while(!q.empty()){
            auto it=q.front();
            int val=it.first;
            int idx=it.second;
            q.pop();
            t++;
            val--;
            if(val == 0 && idx==k) return t;
            if(val > 0){
                q.push({val,idx});
            }
        }
        return t;
    }
};