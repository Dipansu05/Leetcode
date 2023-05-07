long modVal = 1000000007;

class Solution {
    long powMod(int base, int power) {
        long res = 1, multi = base;
        while (power) {
            if (power & 1) res *= multi, res %= modVal;
            multi *= multi, multi %= modVal;
            power >>= 1;
        }
        return res;
    }
public:
    int numSubseq(vector<int> &nums, int target) {
        long res = 0;
        sort(begin(nums), end(nums));
        for (int i = 0, j, len = nums.size(), n, m; i < len; i++) {
            n = nums[i], m = target - n;
            j = upper_bound(begin(nums) + i, end(nums), m) - begin(nums);
            if (j == i) break;
            else res += powMod(2, j - i - 1);
            if (res > modVal) res -= modVal;
        }
        return res;
    }
};