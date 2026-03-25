class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> include(n);
        //vector<int> exclude(n);
        int include[n];
        int exclude[n];
        include[0]=nums[0];
        exclude[0]=0;

        for(int i=1;i<n;i++){
            include[i] = nums[i] + exclude[i-1];
            exclude[i] =max(include[i-1], exclude[i-1]);
        }

        return max(include[n-1], exclude[n-1]);
    }
};