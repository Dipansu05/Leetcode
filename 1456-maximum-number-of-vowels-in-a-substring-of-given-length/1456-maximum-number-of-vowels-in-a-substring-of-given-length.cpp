class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,ans=0;
        int c=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='u' || s[j]=='o' || s[j]=='i' || s[j]=='e' || s[j]=='a') c++;
            while(j-i+1 >k){
              if(s[i]=='u' || s[i]=='o' || s[i]=='i' || s[i]=='e' || s[i]=='a') c--;
                i++;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};