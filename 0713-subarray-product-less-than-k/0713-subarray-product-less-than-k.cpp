class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int ans = 0 ; 
        if(k<=1){
           return 0 ; 
        }
        long long pro = 1 ; 
        int j = 0 ; 
        for(int i =0 ; i<n ; i++){

            pro *= nums[i] ;

            
            
            while(pro>=k){
              pro/= nums[j] ; 
              j++ ; 

            }

            if(pro<k){
                ans += i-j+1 ;
            }
        }

        return ans ; 
    }
};