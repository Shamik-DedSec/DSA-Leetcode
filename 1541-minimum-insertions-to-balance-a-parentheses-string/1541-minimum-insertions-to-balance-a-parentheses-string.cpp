class Solution {
public:
    int minInsertions(string s) {
        int ob=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ob++;
            }
            else{
                if(i+1<s.size() && s[i+1]==')'){
                    i++;
                }
                else{
                    ans++;
                }
                if(ob>0){
                    ob--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans+2*ob;
    }
};