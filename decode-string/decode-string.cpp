class Solution {
public:
    string solve(string &s,int &i){
        string ans;
        while(i<s.size() && s[i]!=']'){
            if(!isdigit(s[i]))  ans+=s[i++];
            
            else{
                int n=0;
                while(i<s.size() && isdigit(s[i]))
                            n=10*n+s[i++]-'0';
                
                    i++;
                    string temp=solve(s,i);
                    i++;
                    while(n--) ans+=temp;
                }
            }
        
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};