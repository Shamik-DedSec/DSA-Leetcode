class Solution{
public:
    void fun(int i,vector<vector<int>>& isConnected,vector<int>& vis){
        vis[i]=1;
        for(int j=0;j<isConnected.size();j++) {
            if(isConnected[i][j]==1 && vis[j]==0){
                fun(j,isConnected,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++) {
            if(vis[i]==0){
                ans++;
                fun(i,isConnected,vis);
            }
        }
        return ans;
    }
};