class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x=n;
        n=(n*(n+1))/2;
        for(int i=0;i<x;i++){
            n-=nums[i];
        }
        return n;
    }
};