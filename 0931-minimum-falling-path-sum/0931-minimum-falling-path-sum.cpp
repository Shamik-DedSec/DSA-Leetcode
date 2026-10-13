int dp[101][101];

int fun(int i,int j,vector<vector<int>> &matrix) {
    int n=matrix.size();

    if(j<0 || j>=n) return 1e9;

    if(i==n-1) return matrix[i][j];

    if(dp[i][j]!=-999999) return dp[i][j];

    int c1=fun(i+1,j-1,matrix);
    int c2=fun(i+1,j,matrix);
    int c3=fun(i+1,j+1,matrix);
    int c4=min(c2,c3);
    return dp[i][j]=matrix[i][j]+min(c1,c4);
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=0;i<101;i++){
             for(int j=0;j<101;j++){
                dp[i][j]=-999999;
            }
        }
        int n=matrix.size();
        int ans=INT_MAX;
        for(int j=0;j<n;j++) {
            ans=min(ans,fun(0,j,matrix));
        }
        return ans;
    }
};