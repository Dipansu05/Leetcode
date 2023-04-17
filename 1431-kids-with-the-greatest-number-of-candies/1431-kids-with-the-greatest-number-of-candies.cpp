class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        int a=INT_MIN;
         vector<bool> ans;
        for(int x:candies){
            if(x>a) a=x;
        }
        for(int x: candies){
            if(x+e>=a) ans.push_back(true);
            else ans.push_back(false);
        }
       
        return ans;
    }
};