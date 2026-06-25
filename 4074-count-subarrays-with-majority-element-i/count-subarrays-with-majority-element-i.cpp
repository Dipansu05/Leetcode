class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans{0};
        for(int left=0;left<n;left++){
            int count{0};
            for(int right=left;right<n;right++){
                if(nums[right]==target) count++;
                int len = right-left+1;
                if(2*count>len) ans++;
            }
        }
        return ans;
    }
};