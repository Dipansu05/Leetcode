class Solution {
public:
    bool pos(vector<int> p, int t,int h){
       int x=0;
        for(int i=0;i<p.size();i++){
            if(p[i]%t==0) x+=p[i]/t;
            else x+=p[i]/t+1;
            if(x>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*(max_element(piles.begin(), piles.end()));
        int ans=-1;
       while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(pos(piles,m,h)){
                ans=m;
                r=m-1;
            }
           else{
               l=m+1;
           }
        }
    
        return ans;
    }
};