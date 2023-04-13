class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        stack<int> temp;
        for(auto val:pushed){
            temp.push(val);
            while(temp.size()>0 && popped[j]==temp.top()){
                j++;
                temp.pop();
            }
        }
        return temp.size()==0;
    }
};