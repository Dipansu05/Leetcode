class Solution {
public:
   long long solve(vector<int> &nums, vector<vector<long long>> &pascal)
    {
        int mod=1000000007;
        if(nums.size()<=2)  return 1;
        vector<int> leftsubtree,rightsubtree;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[0]) leftsubtree.push_back(nums[i]); 
            else    rightsubtree.push_back(nums[i]);
        }
        return (solve(leftsubtree,pascal)%mod*solve(rightsubtree,pascal)%mod*pascal[nums.size()-1][leftsubtree.size()]%mod)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int mod=1000000007;
        int n=nums.size();
        vector<vector<long long>> pascal(n);
        for(int i=0;i<n;i++)
        {
            pascal[i].resize(i+1);
            pascal[i][0]=1;
            pascal[i][i]=1;
            for(int j=1;j<i;j++)
            {
                pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;
            }
        }
        return solve(nums,pascal)-1;
        
    }
};