class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp(101, -1);
        int sm=INT_MAX, lg = INT_MIN;
        for(int n: nums){
            if(n<sm) sm = n;
            if(n>lg) lg = n;
            temp[n] = 1;
        }

        while(sm<lg){
            if(temp[sm] == -1) ans.push_back(sm);
            sm++;
        }

        return ans;
    }
};