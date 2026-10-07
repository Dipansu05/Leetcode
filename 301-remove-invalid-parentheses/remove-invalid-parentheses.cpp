class Solution {
public:
    vector<string> res;
    unordered_set<string> st;
    //int maxLen{0};
    int n;
    void solve(int i, string &s, int count, string& curr, int &maxLen){
        if(count<0) return;
        if(i==n){
            if(count==0){
                if(curr.length()>maxLen){
                    maxLen=curr.length();
                    st.clear();
                }
                if(curr.length()==maxLen){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i]!=')' && s[i]!='('){
            curr.push_back(s[i]);
            solve(i+1, s, count, curr, maxLen);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(i+1,s,count + (s[i]==')' ? -1 : 1), curr, maxLen);
        curr.pop_back();
        solve(i+1,s,count, curr, maxLen);

    }
    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        string curr="";
        int maxLen=0;
        solve(0, s, 0, curr, maxLen);
        //return res;
        return vector<string>(begin(st), end(st));
    }
};