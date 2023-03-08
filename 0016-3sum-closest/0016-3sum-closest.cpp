class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int dif=INT_MAX,ans=0;
        for(int i=0;i<n;i++){
            int f=nums[i];
            int hi=n-1,lo=i+1;
            while(hi>lo){
                int a=f+nums[hi]+nums[lo];
                if(abs(a-t)<dif){
                ans=a;
                dif=abs(a-t);
             }
            
            if(a>t) hi--;
            if(a<t) lo++;
                if(a==t) return ans;
            }
            
        }
        return ans;
    }
};