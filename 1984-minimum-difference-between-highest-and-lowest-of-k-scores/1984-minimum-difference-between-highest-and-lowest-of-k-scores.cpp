class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
        k--;
        int ans=INT_MAX,n=nums.size()-k;
        for(int i=0;i<n;i++){
        if(nums[i+k]-nums[i]<ans) ans=nums[i+k]-nums[i];
        }
        return ans;
    }
};