class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n=s1.size();
        int i=0;

        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            }

            int j=i;
            string a="",b="";

            while(j<n && s1[j]!=s2[j]){
                a+=s1[j];
                b+=s2[j];
                j++;
            }

            ans.push_back({a,b});
            i=j;
        }

        return ans;
    }
};