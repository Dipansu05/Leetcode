class Solution {
public:
    long long pos(vector<int> p, int t){
        long long r=0;
        for(int i=0;i<p.size();i++){
            int tot=ceil(p[i]/(double)t);
            r+=tot;
        }
        return r;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*(max_element(piles.begin(), piles.end()));
        int ans=-1;
       while(l <= r)
        {
            int m = l + (r - l) / 2;
            long long x = pos(piles, m);
            
            if (x <= h)
            {
                ans = m; 
                r = m - 1;
            }
            else l = m + 1;
        }
    
        return ans;
    }
};