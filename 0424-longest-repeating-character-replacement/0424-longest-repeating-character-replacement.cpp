class Solution {
public:
    int characterReplacement(string s, int k) {
       int l =0 ; 
        int mx=0;
        int res=0;
        map<char,int>mp ;
        
        
        for(int i =0 ;i < s.size() ; i++)
        {
            mp[s[i]]++;
            
            mx=max(mx,mp[s[i]]);
            
            if(i-l+1-mx>k)
            {
                mp[s[l]]--;
                l++;
            }
            res=max(res,i-l+1);
            
        }
        
        return res;
    }
};