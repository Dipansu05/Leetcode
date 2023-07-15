class Solution {
public:
    int findMin(vector<int>& nums) {
    int l=0,h=nums.size()-1,m,ans=INT_MAX;
        while(l<=h){
            m=(h+l)/2;
            if(nums[m]<=nums[h]){
                ans=min(nums[m],ans);
                h=m-1;
            }
            else{
                ans=min(ans,nums[l]);
                l=m+1;
        }
        
        }
        return ans;
    }
    
};