class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(gcd(to_string(nums[i])[0]-'0',nums[j]%10)==1) ans++;
            }
        }
        return ans;
    }
};