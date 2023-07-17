class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int t=INT_MIN,ans=0,i;
        for(i=0;i<nums.size();i++){
        if(nums[i]>t){
            t=nums[i];
            ans=i;
        }
        }
        return ans;
    }
};