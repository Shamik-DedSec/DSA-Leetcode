int dp[201][201];

int fun(int i,int j,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();

    if(i>=n || j>=m) return 1e9;
    if(i==n-1 && j==m-1) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    int c1=fun(i+1,j,grid);
    int c2=fun(i,j+1,grid);
    return dp[i][j]=grid[i][j]+min(c1,c2);
}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
        memset(dp,-1,sizeof(dp));
        return fun(0,0,grid);
    }
};