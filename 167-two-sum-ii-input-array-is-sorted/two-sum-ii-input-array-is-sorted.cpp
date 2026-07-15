class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            int l = i+1, r = nums.size()-1;
            int mid;
            while(l<=r){
                mid = l + (r-l) /2 ;

                if(nums[mid]==rem){
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                } else if (nums[mid] > rem) {
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return ans;
    }
};