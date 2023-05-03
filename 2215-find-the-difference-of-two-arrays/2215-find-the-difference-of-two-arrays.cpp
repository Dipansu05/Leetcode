class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,pair<int,int>> n; 
        for(auto i:nums1)
            n[i].first++;
        for(auto i:nums2)
            n[i].second++;
        
        vector<int> a,b;
        for(auto i:n){
            if(i.second.first==0)
                b.push_back(i.first);
            else if(i.second.second==0)
                a.push_back(i.first);
        }
        return {a,b};
    }
};