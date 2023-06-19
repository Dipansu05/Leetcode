class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int t=0,n=gain.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,t);
            t+=gain[i];
        }
        ans=max(ans,t);
        return ans;
    }
};