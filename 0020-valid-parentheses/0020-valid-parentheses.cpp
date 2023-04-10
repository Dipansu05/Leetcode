class Solution {
public:
    bool isValid(string s) {
       stack<char> a;

       for(int i=0;i<s.length();i++){
           if(a.empty()){
               a.push(s[i]);

           }

           else if(s[i]==')' && a.top()=='(' || s[i]=='}' && a.top()=='{' || s[i]==']' && a.top()=='['){
               a.pop();
           }
           else{
               a.push(s[i]);
           }
       }
        
        
       if(a.empty()){
           return true;
       }

       return false;

    }
};