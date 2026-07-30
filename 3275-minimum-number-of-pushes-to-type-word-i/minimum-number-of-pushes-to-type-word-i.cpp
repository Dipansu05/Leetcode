class Solution {
public:
    int minimumPushes(string word) {
        int window_size=8;
        int n = word.size();
        int ans{0};
        for(int i=0;i<n;i++) ans += (i/window_size) + 1;
        return ans;

    }
};