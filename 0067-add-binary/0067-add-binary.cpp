class Solution {
public:
    string fun(int i,int j,string &a,string &b,int carry){
        if(i<0 && j<0){
            if(carry) return "1";
            return "";
        }

        int sum=carry;

        if(i>=0) sum+=a[i]-'0';
        if(j>=0) sum+=b[j]-'0';

        string ans="";
        ans+=char(sum%2+'0');

        return fun(i-1,j-1,a,b,sum/2)+ans;
    }

    string addBinary(string a,string b) {
        return fun(a.size()-1,b.size()-1,a,b,0);
    }
};