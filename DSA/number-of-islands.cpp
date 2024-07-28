class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m =grid[0].size();
        int count=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&visited[i][j]==0){
                    count++;
                    q.push({i,j});
                    visited[i][j]=1;
                    while(!q.empty()){
                        pair<int,int>front=q.front();
                        q.pop();
                        int row = front.first;
                        int col = front.second;
                        for(int i=0;i<4;i++){
                           int newr=row+dx[i];
                            int newc=col+dy[i];
                            if(newr>=0&&newr<n&&newc>=0&&newc<m&&visited[newr][newc]==0&&grid[newr][newc]=='1'){
                                q.push({newr,newc});
                                visited[newr][newc]=1;
                            }
                        }
                    }
                }

            }
        }
        return count;
    }
};