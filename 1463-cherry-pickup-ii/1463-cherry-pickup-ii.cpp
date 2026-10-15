int dp[71][71][71];

int fun(int i,int j,int x,int y,int flag,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();

    if(i>=n||j<0||j>=m||x>=n||y<0||y>=m)return -1e9;

    if(i==n-1){
        int cherries=grid[i][j];
        if(j!=y)cherries+=grid[x][y];
        return cherries;
    }

    if(dp[i][j][y]!=-1)return dp[i][j][y];

    int ans=-1e9;

    for(int a=-1;a<=1;a++){
        for(int b=-1;b<=1;b++){
            int c=fun(i+1,j+a,x+1,y+b,flag,grid);
            ans=max(ans,c);
        }
    }

    int cherries=grid[i][j];
    if(j!=y) cherries+=grid[x][y];

    return dp[i][j][y]=cherries+ans;
}

class Solution{
public:
    int cherryPickup(vector<vector<int>>&grid){
        memset(dp,-1,sizeof(dp));
        int m=grid[0].size();
        return fun(0,0,0,m-1,0,grid);
    }
};