class Solution {
public:
    bool search(vector<int>& n, int t) {
        for(auto i:n){
            if(i==t) return true;
        }
        return false;
    }
};