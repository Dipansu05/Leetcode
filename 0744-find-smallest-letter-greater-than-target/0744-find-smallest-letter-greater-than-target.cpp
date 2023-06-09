class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char t) {
       int l = 0;
        int r = let.size() - 1;
        int m;
        while (l <= r) {
            m = (l + r) / 2;
            if (let[m] <= t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l == let.size() ? let[0] : let[l];
    }
};