class KthLargest {
    int K=0;
    vector<int> v;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        v=nums;
        sort(v.begin(),v.end());
    }
    
    int add(int val) {
        auto it=lower_bound(v.begin(),v.end(),val);
        v.insert(it,val);
        return v[v.size()-K];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */