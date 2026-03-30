class Solution {
public:
    int help(vector<int>& nums){
        int n=nums.size();
        vector<int> include(n);
        vector<int> exclude(n);
        //int include[n];
        //int exclude[n];
        include[0]=nums[0];
        exclude[0]=0;

        for(int i=1;i<n;i++){
            include[i] = nums[i] + exclude[i-1];
            exclude[i] =max(include[i-1], exclude[i-1]);
        }

        return max(include[n-1], exclude[n-1]);
    }
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)   temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

     return max(help(temp1), help(temp2));
    }
};