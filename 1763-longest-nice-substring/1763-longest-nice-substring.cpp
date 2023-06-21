class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2) return "";
        unordered_set<char> u;
        for(int i=0;i<s.size();i++){
            u.insert(s[i]);
        }
        for(int i=0;i<s.size();i++){
            if(u.count(tolower(s[i]))==true and u.count(toupper(s[i]))==true) continue;
            string t1=longestNiceSubstring(s.substr(0,i));
            string t2=longestNiceSubstring(s.substr(i+1));
            
            return t1.size()>=t2.size() ?  t1 : t2;
        }
        return  s;
    }
};