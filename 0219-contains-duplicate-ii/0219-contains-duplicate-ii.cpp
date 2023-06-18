class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(s.size()>k){
                s.erase(nums[i]);
                i++;
            }
            if(s.find(nums[j])!=s.end()) return true;
            else s.insert(nums[j]);
        }
        return false;
    }
};