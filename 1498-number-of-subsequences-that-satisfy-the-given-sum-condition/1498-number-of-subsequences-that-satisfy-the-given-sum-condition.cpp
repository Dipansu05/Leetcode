class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
        int n=nums.size(),res=0,l=0,r=n-1,mod=1e9+7;
        vector<int>v(n,1);
        for(int i=1;i<n;i++)
        {
            v[i]=(v[i-1]*2)%mod;
        }
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
                r--;
            else
            {
                res=(res+v[r-l])%mod;
                l++;
            }
        }
        return res;      
    }
};