class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMin(n+1, INT_MAX);
        int l{0};
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            suffixMin[i]=min(suffixMin[i+1], nums[i]);
        }

        while(l<n){
            int r=l;
            int componentMax=nums[l];

            while(r+1 < n && componentMax> suffixMin[r+1]){
                r++;
                componentMax=max(componentMax, nums[r]);
            }
            for(int i=l;i<=r;i++){
                ans[i]=componentMax;
            }
            l=r+1;
        }
        return ans;

    }
};