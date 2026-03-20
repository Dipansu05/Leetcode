class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        partition(s,0,part,result);
        return result;
    }

    void partition(string &s, int start, vector<string>& part, vector<vector<string>> &result){
        int n=s.size();
        if(start==s.size()){
            result.push_back(part);
        }else{
            for(int i=start;i<n;i++){
                if(isPalindrome(start,i,s)){
                    part.push_back(s.substr(start,i-start+1));
                    partition(s,i+1,part,result);
                    part.pop_back();
                }
            }
        }
    }

    bool isPalindrome(int start, int end, string& temp){
        while(start<end){
            if(temp[start]!=temp[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};