class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n,0);
        for(auto x: nums){
            if(x<1 || x>=n) return false;
            freq[x]++;
        }
        for(int i=1;i<n-1;i++){
            if(freq[i]!=1) return false;
        }
        return freq[n-1]==2;
    }
};