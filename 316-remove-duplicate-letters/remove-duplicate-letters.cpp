class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        string res="";
        unordered_map<char, int> M;
        stack<char> S;
        for(char c: s){
            M[c]++;
        }
        unordered_set<char> seen;
        for(char c: s){
            M[c]--;
            if(seen.count(c)) continue;
            while(!S.empty() && c<S.top() && M[S.top()]>0){
                seen.erase(S.top());
                S.pop();
            }
            S.push(c);
            seen.insert(c);
        }
        while(!S.empty()){
            res = S.top() + res;
            S.pop();
        }
        return res;
        

    }
};