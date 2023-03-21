class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
       int c =0;
        for(int i=0;i<f.size();i++){
            if(f[i]==0 and (i==0 || f[i-1]==0) and (i==f.size()-1 || f[i+1]==0)){
                f[i]=1;
                c++;
                }
        }
        if(c < n)  return false;
        return true;
    }
};