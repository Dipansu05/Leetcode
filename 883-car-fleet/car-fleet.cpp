class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, int>> temp;
        for(int i=0;i<pos.size();i++){
            temp.push_back({pos[i], speed[i]});
        }
        sort(temp.rbegin(), temp.rend());
        vector<double> stack;
        for(auto p: temp){
            stack.push_back((double)(target-p.first)/p.second);
            if(stack.size()>=2 && stack.back()<=stack[stack.size()-2]){
                stack.pop_back();
            }
        }
        return stack.size();
    }
};