class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,t=1,j=0;
        if(k<=1) return 0;
        for(int i=0;i<n;i++){
            t*=nums[i];
            while(t>=k){
                t/=nums[j];
                j++;
            }
            if(t<k){
                ans+=i-j+1;
                }
        }
        return ans;
    }
};