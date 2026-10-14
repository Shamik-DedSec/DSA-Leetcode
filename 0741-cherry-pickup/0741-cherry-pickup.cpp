int dp[51][51][51][51][2];

int fun(int i,int j,int x,int y,int flag,vector<vector<int>> &grid){
    int n=grid.size();
    if(i>=n || j>=n || x<0 || y<0) return -1e9;
    if(i<0 || j<0 || x>=n || y>=n) return -1e9;

    if(grid[i][j]==-1 || grid[x][y]==-1) return -1e9;
    

    if(flag==0&&i==n-1&&j==n-1){
       if(x==n-1&&y==n-1)return grid[i][j];
       return fun(i,j,x,y,1,grid);
    }
    if(flag==1 && i==0 && j==0){
        return 0;
    }
    
    if(dp[i][j][x][y][flag]!=-1) return dp[i][j][x][y][flag];
    int ans=-1e9;

    if(flag==0){
        int a=fun(i+1,j,x+1,y,flag,grid);
        int b=fun(i+1,j,x,y+1,flag,grid);
        int c=fun(i,j+1,x+1,y,flag,grid);
        int d=fun(i,j+1,x,y+1,flag,grid);
        ans=max(max(a,b),max(c,d));
    }else{
        int a=fun(i-1,j,x-1,y,flag,grid);
        int b=fun(i-1,j,x,y-1,flag,grid);
        int c=fun(i,j-1,x-1,y,flag,grid);
        int d=fun(i,j-1,x,y-1,flag,grid);
        ans=max(max(a,b),max(c,d));
    }

    int cherries=grid[i][j];
    if(i!=x || j!=y){
        cherries=cherries+grid[x][y];
    }
    if(ans==-1e9) return dp[i][j][x][y][flag]=-1e9;
    return dp[i][j][x][y][flag]=cherries+ans;
}
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return max(0,fun(0,0,0,0,0,grid));
    }
};

