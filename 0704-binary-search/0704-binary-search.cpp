class Solution {
public:
    int search(vector<int>& n, int t) {
        int l = 0, r = n.size()-1, m;
        while(l <= r){
            m = ( l + r) /2;
            if ( n[m] == t) return m;
            else if(n[m] < t) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};