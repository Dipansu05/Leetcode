class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for( auto &it : mp){
            auto idx = it.second;

            if(idx.size()<3) continue;
            for(int i=0;i+2<idx.size();i++){
                int dist=2*(idx[i+2]-idx[i]);
                ans=min(ans,dist);
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};