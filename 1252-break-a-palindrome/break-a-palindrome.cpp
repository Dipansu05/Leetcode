class Solution {
public:
    string breakPalindrome(string pali) {
        if(pali.size()==1) return "";
        int i=0, j=pali.size()-1;
        while(i<j){
            if(pali[i]!='a'){
                pali[i]='a';
                return pali;
            }
            i++;
            j--;
        }
        pali[(pali.size()-1)]='b';
        return pali;
        
    }
};