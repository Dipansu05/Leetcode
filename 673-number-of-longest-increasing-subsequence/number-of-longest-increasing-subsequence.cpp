class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n,1), cnt(n,1);

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                if(len[prev]+1 > len[i]){
                    len[i] = len[prev] + 1;
                    cnt[i] = cnt[prev];
                }

                else if(len[prev]+1 == len[i]) cnt[i] += cnt[prev];
            }
        }
        }

    int maxLen=*max_element(len.begin(), len.end());
    int ans{0};

    for(int i=0;i<n;i++){
        if(len[i]==maxLen) ans += cnt[i];
    }
    return ans;
    }
};