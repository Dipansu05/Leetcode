class Solution {
public:
    int search(vector<int>& n, int t) {
        int l=0,h=n.size()-1,m;
        while(l<=h){
            m=(h+l)/2;
            if(n[m]==t) return m;
            else if(n[m]<t) l=m+1;
            else h=m-1;
        }
        return -1;
    }
};