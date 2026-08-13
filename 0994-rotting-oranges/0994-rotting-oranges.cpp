class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue< pair<pair<int,int>,int> >q; //row,col,time

        //put all rotten in queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        //solve
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=1; i<=size; i++){
                auto it = q.front();
                int row=it.first.first;
                int col=it.first.second;
                int time=it.second;
                q.pop();

                //neighbours
                for(int j=0; j<=3; j++){
                    int nr=row+dx[j];
                    int nc=col+dy[j];

                    if(nr>=0 && nr<=m-1 && nc>=0 && nc<=n-1 &&
                    !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        grid[nr][nc]=2;
                        q.push({{nr,nc},time+1});
                        ans=time+1;
                    }
                }
            }
        }
        //check if any fresh left
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};