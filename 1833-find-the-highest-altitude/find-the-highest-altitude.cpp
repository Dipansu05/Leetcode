class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int t{0};
        int ans = INT_MIN;
        for(int i=0;i<gain.size();i++){
            ans = max(ans, t);
            t += gain[i];
        }
        return max(ans,t);
    }
};