class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-1,m;
        if(h==0){
            return nums[0];
        }else if( nums[0]!=nums[1]){
            return nums[0];
        }else if(nums[h]!=nums[h-1]){
            return nums[h];
        }
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]!= nums[m+1] and nums[m]!=nums[m-1]) return nums[m];
            if((m%2)==0){
                if(nums[m]==nums[m+1]) l=m+1;
                else h=m-1;
            }
            else{
                if(nums[m]==nums[m-1]) l=m+1;
                else h=m-1;
            }
        }
        return nums[m];
    }
};