class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxn=INT_MIN, minn=INT_MAX;
        int maxid=-1, minid=-1;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minn){
                minn=nums[i];
                minid=i;
            }
            if(nums[i]>maxn){
                maxn=nums[i];
                maxid=i;
            }
        } 
        int rem_front=max(minid,maxid)+1;
        int rem_back=n-min(minid,maxid);
        int rem_both=min(minid+1+(n-maxid), maxid+1+(n-minid));
        return min(rem_front, min(rem_back, rem_both));
    }
};