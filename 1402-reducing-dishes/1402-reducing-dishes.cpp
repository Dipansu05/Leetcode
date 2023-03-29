class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int m=0;
        int sum;
        int n=s.size();
        for(int i=0;i<n;i++){
            int t=1,x=i,sum=0;
            while(x<n){
                sum+=t*(s[x]);
                t++;
                x++;
            }
            m=max(m,sum);
        }
          return m;
    }
  
};