class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> temp;
        for(int x: nums) temp[x]++;
        for(int i: nums) if(temp[i]>1) return true;
        return false;
    }
};