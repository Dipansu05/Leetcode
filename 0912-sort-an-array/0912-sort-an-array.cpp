class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> p(nums.begin(),nums.end());
        int i=0,n=nums.size()-1;
        while(!p.empty()){
            i=p.top();
            nums[n]=i;
            n--;
            p.pop();
        }
        return nums;
    }
};