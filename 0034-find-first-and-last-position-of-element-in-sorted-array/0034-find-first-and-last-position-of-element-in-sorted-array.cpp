class Solution {
public:
    int lb(vector<int>& nums, int t){
        int l=0,h=nums.size()-1,m,ans=nums.size();
        while(l<=h){
            m=(h+l)/2;
            if(nums[m]>=t){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
        
    }
    int up(vector<int>& nums, int t){
        int l=0,h=nums.size()-1,m,ans=nums.size();
        while(l<=h){
            m=(h+l)/2;
            if(nums[m]>t){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        if(nums.size()==0) return ans;
        int l=lb(nums,target);
        if(l==nums.size() || nums[l]!=target) return ans;
        ans[0]=l;
        int u=up(nums,target);
        ans[1]=u-1;
        return ans;
    }
};