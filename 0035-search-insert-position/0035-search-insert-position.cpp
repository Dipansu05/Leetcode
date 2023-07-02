class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
    int l=0,h=nums.size()-1,m,ans=nums.size();
        while(l<=h){
           int m=(h+l)/2;
            if(nums[m]>=t){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};