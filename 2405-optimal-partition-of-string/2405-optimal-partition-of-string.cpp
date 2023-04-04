class Solution {
public:
    int ans=1;
    int partitionString(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]){
                ans++;
                m.clear();
                m[s[i]]++;
            }
            else m[s[i]]++;
        }
        return ans;
    }
};