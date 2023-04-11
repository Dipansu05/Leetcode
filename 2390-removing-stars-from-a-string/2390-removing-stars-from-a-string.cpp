class Solution {
public:
    string removeStars(string s) {
      vector<char> ans;
        for(auto i : s) {
            if(ans.size() != 0 && ans.back() != '*' && i == '*') ans.pop_back();
            else ans.push_back(i);
        }
        string answer = "";
        for (auto i : ans) answer += i;
        return answer;
    }
};