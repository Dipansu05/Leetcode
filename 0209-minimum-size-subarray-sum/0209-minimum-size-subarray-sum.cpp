class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int i=0,j=0,ans=INT_MAX,s=0;
        while(j<nums.size()){
         s+=nums[j];
            if(s<t) j++;
            else if(s==t){
                ans=min(ans,j-i+1);
                j++;
            }
            else if(s>t)
            {
                while(s>t)
                {
                    ans=min(ans,j-i+1);
                    s=s-nums[i];
                    i++;
                }
                if(s==t)
                {
                    ans=min(ans,j-i+1);
                }
                j++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};