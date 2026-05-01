class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum{0}, f{0};
        int n=nums.size();

        for(int i=0;i<n;i++){
            sum += nums[i];
            f   += i*nums[i];
        }

        int ans{f};

        for(int i=1;i<n;i++){
            f+=sum-n*nums[n-i];
            ans=max(ans,f);
        }

        return ans;
    }
};