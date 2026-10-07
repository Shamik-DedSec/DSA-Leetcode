int dp[201][201];

int fun(int i,int j,vector<vector<int>>& t){
    if(i==0) return t[0][0];
    if(dp[i][j]!=-1) return dp[i][j];
    int c1=1e9;
    int c2=1e9;
    if(j<t[i-1].size()){
        c1=fun(i-1,j,t);
    }   
    if(j-1>=0){
        c2=fun(i-1,j-1,t);
    }
    return dp[i][j]=t[i][j]+min(c1,c2);
}
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t){
        memset(dp,-1,sizeof(dp));

        int n=t.size();
        int ans=1e9;

        for(int j=0;j<t[n-1].size();j++){
            ans=min(ans,fun(n-1,j,t));
        }

        return ans;
    }
};