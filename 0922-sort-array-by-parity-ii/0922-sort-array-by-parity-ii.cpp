class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int o=1,e=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i])%2==0){
                ans[e]=nums[i];
                e+=2;
            }
            else{
                ans[o]=nums[i];
                o+=2;
            }
        }
        return ans;
    }
};