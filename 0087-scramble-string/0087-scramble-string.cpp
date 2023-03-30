class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool isScramble(string s1, string s2) {
        
        if(s1.length()!=s2.length())return false;
        if(s1.length()==1)return s1[0]==s2[0];
        if(s1==s2)return true;
        string concat = s1+"/"+s2;
        if(mp.find(concat)!=mp.end())return mp[concat];
        mp[concat] =false;
        vector<int> c(256,0);
        int  n = s1.length();
        for(int i=0;i<n;i++){
            c[s1[i]]++;
            c[s2[i]]--;
        }
        for(auto ch:s1){
            if(c[ch]!=0)return false;
        }
        for(int i=1;i<n;i++){
            
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&& 
               isScramble(s1.substr(i),s2.substr(i)))return   mp[concat]= true;
            if(isScramble(s1.substr(0,i),s2.substr(n-i))&& 
               isScramble(s1.substr(i),s2.substr(0,n-i)))return mp[concat]= true;
        }
        
        return false;
    }
};