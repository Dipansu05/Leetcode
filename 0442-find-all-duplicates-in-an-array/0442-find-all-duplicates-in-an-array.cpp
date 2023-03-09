class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> ans;
        int z=nums.size();
        for(int i=0;i<z;i++){
            nums[i]=nums[i]-1;
        }
        for(int i=0;i<z;i++){
            int x=nums.at(i)%z;
            
            nums.at(x)+=z;
        }
        for(int i=0;i<z;i++){
            if(nums.at(i)/z>1){
            ans.push_back(i+1);}
        }
        return ans;
    }
};