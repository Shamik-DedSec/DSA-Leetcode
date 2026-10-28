//int dp[1001][1001][1024];

int fun(int i,int j,vector<vector<int>>&grid,int x,vector<vector<vector<int>>>&dp){
    int m=grid.size();
    int n=grid[0].size();

    if(i>=m || j>=n) return 1e9;

    if(i==m-1 && j==n-1) return grid[m-1][n-1] ^ x;

    if(dp[i][j][x]!=-1) return dp[i][j][x];

    int a=fun(i+1,j,grid,x ^ grid[i][j],dp);
    int b=fun(i,j+1,grid,x ^ grid[i][j],dp);

    return dp[i][j][x]=min(a,b);
}

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,
                                                    vector<int>(1024,-1)));
        return fun(0,0,grid,0,dp);
    }
};