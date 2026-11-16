class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=nums[i];

            for(int j=i;j<n;j++){
                a=a&nums[j];
                b=min(b,nums[j]);

                if(a==b){
                    ans++;
                }
            }
        }

        return ans;
    }
};