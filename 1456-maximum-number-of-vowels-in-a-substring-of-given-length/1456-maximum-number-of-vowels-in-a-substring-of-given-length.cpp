class Solution {
public:
    int maxVowels(string s, int k) {
     int i=0;
        int count = 0;
        int ans = 0;
        
        for(int j= 0 ; j < s.size() ; j++){
                
            if(s[j] == 'a') count++;
            if(s[j] == 'e') count++;
            if(s[j] == 'i') count++;
            if(s[j] == 'o') count++;  
            if(s[j] == 'u') count++;
            
            while(j-i+1 > k){          
                
                if(s[i] == 'a') count--;
                if(s[i] == 'e') count--;
                if(s[i] == 'i') count--;
                if(s[i] == 'o') count--;  
                if(s[i] == 'u') count--;
                
                i++;
              
            }
            
            ans = max(ans,count);    
        }
        
        return ans;
    }
};