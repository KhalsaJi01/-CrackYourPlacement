class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intial = image[sr][sc];
        int n =image.size();
        int m =image[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        while(!q.empty())
        {
            pair<int,int>front=q.front();
            q.pop();
            int row=front.first;
            int col = front.second;
            image[row][col]=color;
            for(int i=0;i<4;i++){
                int newr=row+dx[i];
                int newc=col+dy[i];
                if(newr>=0&&newr<n&&newc>=0&&newc<m&&visited[newr][newc]==0&&image[newr][newc]==intial){
                    q.push({newr,newc});
                    visited[newr][newc]=1;
                }
            }
        }
        return image;
    }
};