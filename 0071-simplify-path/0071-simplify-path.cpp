class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        stack<string> s;
        string ans="";
        string temp="";
        for(int i=0;i<path.size();i++){
            if(path[i]!='/') temp+=path[i];
            else{
                v.push_back(temp);
                temp="";
            }
        }
        v.push_back(temp);
        for(int i=0;i<v.size();i++){
            if(!s.empty() && v[i]=="..") s.pop();
            else if(!(v[i]=="") && !(v[i]==".") && !(v[i]=="..")) s.push(v[i]);
        }
        if(s.empty()) return "/";
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        return ans;
    }
};