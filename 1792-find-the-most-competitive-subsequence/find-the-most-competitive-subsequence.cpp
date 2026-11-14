class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> r;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(!r.empty() && 
            r.back() > nums[i] &&
            (k-(r.size()-1))<=(n-i)){
                r.pop_back();
            }
            if(r.size() < k) r.push_back(nums[i]);
        }
        return r;
    }
};