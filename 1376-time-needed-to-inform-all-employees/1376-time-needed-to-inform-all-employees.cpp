class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int,int>>q; //idx,time
        int ans=0;  
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            int e=i; //employee
            int m=manager[i]; //manager
            if(m!=-1){
                adj[m].push_back(e);
            }
        }

        //solve
        q.push({headID,0});
        while(!q.empty()){
            int size=q.size();
            for(int i=1; i<=size; i++){
                int manager=q.front().first;
                int time=q.front().second;
                //manager tak baat aane mein 'time' lag chuka hai, ab wo apne employes ko batayega
                q.pop();
                ans=max(ans,time);
                for(auto it: adj[manager]){
                    //it are employes of manager
                    q.push({it,informTime[manager]+time});
                }
            }
        }
        return ans;
    }
};