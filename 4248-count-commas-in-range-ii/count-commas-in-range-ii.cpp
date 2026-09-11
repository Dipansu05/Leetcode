class Solution {
public:
    using ll = long long;
    long long countCommas(long long n) {
        ll ans = 0;
        ll commas = 1;
        ll lower = 1000;
        while ( lower <= n ){
            ll upper = 1000 * lower - 1;
            if (upper > n) upper = n;
            ll nums_comm = upper - lower + 1;
            ans += (commas * nums_comm);
            commas ++;
            lower *= 1000;
        }
        return ans;
    }
};