class Solution {
public:
    int digits(int x){
        int count{0};
        while(x){
            count++;
            x /= 10;
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int ans{0};
        for(int num: arr1){
            while(num){
                st.insert(num);
                num /= 10;
            }
        }

        for(int num: arr2){
            int x = num;
            int len = digits(x);
            while(x){
                if(st.count(x)){
                    ans=max(ans,len);
                }
                x /= 10;
                len--;
            }
        }

        return ans;
    }
};