class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int x:spells){
            long long need=(success+x-1)/x;
            auto it=lower_bound(potions.begin(),potions.end(),need);
            ans.push_back(potions.end()-it);
        }
        return ans;
    }
};