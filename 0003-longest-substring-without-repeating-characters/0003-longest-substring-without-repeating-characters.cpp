class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int v[256]={0};
    int l=0,r=0,ans=0;

    while(r<s.length()){
      v[s[r]]++;

      while(v[s[r]]>1){
        v[s[l]]--;
        l++;
      }
      ans=max(ans,r-l+1);
      r++;
    }
    return ans;
    }
};