int fun(string &s,int &i){
    int ans=0;
    while(i<s.size() && s[i]!=')'){
        if(s[i]=='('){
            i++;
            int x=fun(s,i);
            if(x==0)
                ans+=1;
            else
                ans+=2*x;

            i++;
        }
    }
    return ans;
}
class Solution {
public:
    int scoreOfParentheses(string s){
        int i=0;
        return fun(s,i);
    }
};