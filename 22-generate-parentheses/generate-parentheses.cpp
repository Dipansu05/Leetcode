class Solution {
public:
    vector<string> res;
    bool isValid(string &temp){
        int count{0};
        for(char c: temp){
            if(c=='(') count++;
            else count--;
            if(count<0) return false;
        }
        return count == 0;
    }
    void solve(string &temp, int n){
        if(temp.size()==2*n){
            if(isValid(temp)){
                res.push_back(temp);
            }
            return;
        }
        temp.push_back('(');
        solve(temp, n);
        temp.pop_back();
        temp.push_back(')');
        solve(temp, n);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        solve(temp, n);
        return res;
    }
};