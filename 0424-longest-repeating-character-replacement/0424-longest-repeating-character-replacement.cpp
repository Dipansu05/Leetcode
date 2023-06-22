class Solution {
public:
    int characterReplacement(string s, int k) {
      map<char,int>  m;
        int ans=0,l=0,mx=0,n=s.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            mx=max(mx,m[s[i]]);
            if(i-l+1-mx>k){
                m[s[l]]--;
                l++;
            }
            ans=max(i-l+1,ans);
        }
        return ans;
    }
};