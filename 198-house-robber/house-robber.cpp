class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        int prev2=nums[0];
        int prev1=max(nums[0], nums[1]);
        int curr = prev1;
        for(int i=2;i<nums.size();i++){
            int pick = nums[i]+prev2;
            int not_pick = prev1;
            curr = max(pick, not_pick);

            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};