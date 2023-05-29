class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int a = p[0]+p[1];
        if(a<=m)
            return m-a;
        else
            return m;
    }
};