class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int s=0,e=p.size()-1;
        int ans=0;
        while(s<=e){
            if(p[e]>=limit){
                ans++;
                e--;
            }
            else if(p[s]+p[e]<=limit){
                ans++;
                e--;
                s++;
            }
            else{
                e--;
                ans++;
            }
        }
        return ans;
    }
};