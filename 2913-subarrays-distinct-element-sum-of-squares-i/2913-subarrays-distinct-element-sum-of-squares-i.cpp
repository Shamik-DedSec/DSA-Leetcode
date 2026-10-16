class Solution {
public:
    int sumCounts(vector<int>& nums) {
        

        int i,s=0;

        for(i=0;i<size(nums);i++){
            map<int,int>m1;
            for(int j=i;j<size(nums);j++){
               m1[nums[j]]++;
             

               s=s+(m1.size()*m1.size());
            }
        }

        return s;
    }
};