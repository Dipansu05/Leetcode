class Solution {
public:
    int digitSum(int n){
        int sum{0};
        while(n>0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count{0};
        auto lambda = [&](int n1, int n2){
            int nsum1=digitSum(n1);
            int nsum2=digitSum(n2);
            if (nsum1!=nsum2) return nsum1 < nsum2;
            return n1<n2;
        };
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end(), lambda);
        unordered_map<int, int> val;
        for(int i=0;i<n;i++) val[nums[i]]=i;
        for(int i=0;i<n;i++){
            int expected=sorted[i];
            int current=nums[i];
            if(expected==current) continue;
            int idx = val[expected];
            nums[i] = expected;
            nums[idx] = current;
            val[expected]=i;
            val[current]=idx;
            count++;
        }
        return count;
    }
};