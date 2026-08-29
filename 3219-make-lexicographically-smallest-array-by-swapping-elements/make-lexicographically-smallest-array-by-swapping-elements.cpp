class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        for(int i=0;i<n;i++){
            sorted[i].first=nums[i];
            sorted[i].second=i;
        }
        sort(begin(sorted), end(sorted));
        int low=0;
        vector<int> sorted_indices(n);
        sorted_indices[0]=sorted[0].second;
        for(int i=1;i<n;i++){
            if((sorted[i].first-sorted[i-1].first)>limit){
                sort(begin(sorted_indices)+low,
                     begin(sorted_indices)+i);
                low = i;
            }
            sorted_indices[i] = sorted[i].second;
        }
        sort(begin(sorted_indices)+low, end(sorted_indices));
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[sorted_indices[i]] = sorted[i].first;
        }
        return ans;
    }
};