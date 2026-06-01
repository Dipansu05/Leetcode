class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans {0};
        int i = 0, j = people.size()-1;
        sort(begin(people), end(people));
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
                ans++;
            }else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};