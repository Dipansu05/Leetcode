class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        int nd = nums.size()-k;
        for(int i=0;i<nums.size();i++){
            while(!stack.empty() && nd && nums[i]<stack.back()){
                stack.pop_back();
                nd--;
            }
            stack.push_back(nums[i]);
        }
        return vector<int>(stack.begin(), stack.begin()+k);
        
    }
};