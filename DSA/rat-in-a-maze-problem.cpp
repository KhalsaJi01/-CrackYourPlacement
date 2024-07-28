//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void solve(vector<vector<int>> &mat,int n,int m,vector<vector<int>> visited,vector<string>&ans,string temp,int sr,int sc){
      if(sr==n-1&&sc==m-1){
          ans.push_back(temp);
          return;
      }
      visited[sr][sc]=1;
      int newr =sr;
      int newc=sc;
      if(newr+1>=0&&newr+1<n&&mat[newr+1][newc]==1&&visited[newr+1][newc]==0){
          temp.push_back('D');
          solve(mat,n,m,visited,ans,temp,newr+1,newc);
          temp.pop_back();
      }
      if(newc+1>=0&&newc+1<m&&mat[newr][newc+1]==1&&visited[newr][newc+1]==0){
          temp.push_back('R');
          solve(mat,n,m,visited,ans,temp,newr,newc+1);
          temp.pop_back();
      }
            if(newr-1>=0&&newr-1<n&&mat[newr-1][newc]==1&&visited[newr-1][newc]==0){
          temp.push_back('U');
          solve(mat,n,m,visited,ans,temp,newr-1,newc);
          temp.pop_back();
      }
            if(newc-1>=0&&newc-1<m&&mat[newr][newc-1]==1&&visited[newr][newc-1]==0){
          temp.push_back('L');
          solve(mat,n,m,visited,ans,temp,newr,newc-1);
          temp.pop_back();
      }
      
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n =mat.size();
        int m =mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<string>ans;
        string temp;
        if(mat[n-1][n-1]==0 ||mat[0][0]==0)
        {
            return ans;
        }
        solve(mat,n,m,visited,ans,temp,0,0);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends