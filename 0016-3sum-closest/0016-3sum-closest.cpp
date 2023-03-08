class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int dif=INT_MAX,ans=0;
        for(int i=0;i<nums.size();i++){
            int f=nums[i];
            int s=i+1,e=nums.size()-1;
            while(s<e){
                if(f+nums[e]+nums[s]==target) return target;
                else if(abs(f+nums[e]+nums[s]-target)<dif){
                    dif=abs(f+nums[e]+nums[s]-target);
                    ans=f+nums[e]+nums[s];
                    
                }
                if(f+nums[e]+nums[s]>target) e--;
                else s++;
            }
        }
        return ans;
    }
};