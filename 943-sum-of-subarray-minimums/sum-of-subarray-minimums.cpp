class Solution {
public:
vector<int> getNSL(vector<int>& arr, int n){
    stack<int> st;
    vector<int> NSL(n,0);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>= arr[i]) st.pop();
        if(st.empty()) NSL[i]=-1;
        else NSL[i]=st.top();
        st.push(i);
    }
    return NSL;
}
vector<int> getNSER(vector<int>& arr, int n){
    stack<int> st;
    vector<int> NSER(n,0);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()) NSER[i]=n;
        else NSER[i] = st.top();
        st.push(i);
    }
    return NSER;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int M=(int)(1e9+7);
        vector<int> NSL=getNSL(arr,n);
        vector<int> NSER=getNSER(arr,n);
        typedef long long ll;
        ll sum=0;
        for(int i=0;i<n;i++){
            ll left=i-NSL[i];
            ll right = NSER[i]-i;
            ll total=(left*right)%M;
            sum = (sum+(total*arr[i])%M)%M;
        }
        return sum;
    }
};