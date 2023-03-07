class Solution {
public:
    bool enough(vector<int> time,long long t, int tot){
        long long trip=0;
        for(int i:time){
            trip+=t/i;
        }
        return trip>=tot;
    }
    long long minimumTime(vector<int>& time, int tot) {
        long long l=1;
       long long r = 1LL * *max_element(time.begin(), time.end()) * tot;
        while(l<r){
            long long m=(l+r)/2;
            if(enough(time,m,tot)) r=m;
            else l=m+1;
        }
        return l;
    }
};