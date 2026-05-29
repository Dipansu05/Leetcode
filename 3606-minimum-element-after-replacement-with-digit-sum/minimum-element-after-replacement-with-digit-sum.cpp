class Solution {
public:
    int sum(int n){
        int sum{0};
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int n: nums){
            ans=min(ans,sum(n));
        }
        return ans;
    }
};