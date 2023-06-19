class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long t=0,ans=0;
        unordered_map<int,int> m;
        int i=0,n=nums.size();
        while(i<k ){
            m[nums[i]]++;
            t+=nums[i];
            i++;
        }
        if(m.size()==k) ans=t;
        while(i<n){
            m[nums[i]]++;
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0) m.erase(nums[i-k]);
            t+=nums[i];
            t-=nums[i-k];
            if(m.size()==k) ans=max(t,ans);
            i++;
        }
        return ans;
    }
};