class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l=0,h=nums.size()-1,m;
        while(l<=h){
            m=(h+l)/2;
            if(nums[m]==t) return m;
            if(nums[l]<=nums[m]){
                if(nums[l]<=t and t<=nums[m]) h=m-1;
                else l=m+1;
            }
            else{
                if(nums[m]<=t and t<=nums[h]) l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};