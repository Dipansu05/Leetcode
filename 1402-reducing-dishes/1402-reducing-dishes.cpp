class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        int sum=s[n-1],val=s[n-1],m=0;
        for(int i=n-2;i>=0;i--){
            sum+=s[i];
            val+=sum;
            if(val>sum){
                m=max(m,val);
            }
        }
        return m>0 ? m:0;
    }
};