class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<parent.size(); i++){
            int p=parent[i];
            int c=i;
            if(p!=-1){
                adj[p].push_back(c);
            }
        }
        
        //nums[i] *(h-d+1)
        //nums[i]*h - d*nums[i] + nums[i]
        

        //evaluate nums[i]-d*nums[i] = val
        //add h * (sum of all nums[i])
        queue<int> q;
        long long h=0;
        long long d=1;
        long long val=0;
        long long sum=0;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            for(int i=1; i<=size; i++){
                int node=q.front();
                q.pop();

                val+=nums[node]-d*(nums[node]);
                sum+=nums[node];
                for(auto it: adj[node]){
                    q.push(it);
                }
            }
            d++;
            h++;
        }
        cout << h << endl;
        long long ans=val+h*(sum);
        return ans;
    }
};