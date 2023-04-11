class Solution {
public:
    string removeStars(string s) {
string answer="";

        vector<char> vec;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='*')       
                vec.push_back(s[i]);
            else if(vec.size()!=0 && s[i]=='*')  
                vec.pop_back();  
        }
        for(auto x: vec)
            answer+=x;
        
        return answer;
    }
};