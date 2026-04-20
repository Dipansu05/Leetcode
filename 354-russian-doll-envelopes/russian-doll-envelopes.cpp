class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });

        int n=envelopes.size();
        if(n==0) return 0;
        vector<int> tails;
        for(auto e: envelopes){
            int ht=e[1];
            auto it = lower_bound(tails.begin(), tails.end(), ht);
            if(it==tails.end())
            {
                tails.push_back(ht);
            }else{
                *it=ht;
            }
        }
        return tails.size();
    }
};