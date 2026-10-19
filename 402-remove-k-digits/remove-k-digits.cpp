class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans =  "";
        for(auto ch: num){
            while(ans.size() && ch<ans.back() && k){
                ans.pop_back();
                k--;
            }
            if(ans.size()==0 && ch=='0') continue;
            ans.push_back(ch);
        }
        while(ans.size() && k--) ans.pop_back();
        if(ans.size()>0) return ans;
        return "0";
    }
};