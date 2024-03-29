class Solution {
public:
 const int MOD = 1e9 + 7;
typedef long long ll;

int numberOfArrays(string s, int k) {
	int n = s.size(), m = to_string(k).size(); // log10(k) + 1;
	vector<ll> dp(n + 1, 0); dp[n] = 1;
	string str = "";
	for (int i = n - 1; i >= 0; --i) {
		str = s[i] + str;
		if (str.size() > m) str.erase(prev(str.end()));
		if (s[i] == '0') continue;
		int jend = min(i + m - (stoll(str) > k), n);
		for (int j = i + 1; j <= jend; ++j) {
			dp[i] += dp[j];
		}
		dp[i] %= MOD;
	}
	return dp[0];
}
};