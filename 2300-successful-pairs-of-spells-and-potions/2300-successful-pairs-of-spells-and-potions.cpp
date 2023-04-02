class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int len = spells.size();
        long long threshold;
        double spellVal;
        vector<int> res(len);
        sort(begin(potions), end(potions));
        for (int i = 0; i < len; i++) {
            spellVal = spells[i];
            threshold = ceil(success / spellVal);
            res[i] = end(potions) - lower_bound(begin(potions), end(potions), threshold);
        }
        return res;
    }
};