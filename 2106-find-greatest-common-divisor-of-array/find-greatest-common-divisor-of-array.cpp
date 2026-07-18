class Solution {
public:
    int findGCD(vector<int>& nums) {
        int bgst=INT_MIN;
        int smlst=INT_MAX;
        for(int i: nums){
            if (i>bgst) bgst =i;
            if (i<smlst) smlst=i;
        }
        return __gcd(bgst,smlst);
    }
};