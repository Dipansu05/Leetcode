class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
        k--;
        int ans=INT_MAX;
        for(int i=0;i<nums.size()-k;i++){
        if(nums[i+k]-nums[i]<ans) ans=nums[i+k]-nums[i];
        }
        return ans;
    }
};