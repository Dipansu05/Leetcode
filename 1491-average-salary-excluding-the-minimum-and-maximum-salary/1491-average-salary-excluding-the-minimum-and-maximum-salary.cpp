class Solution {
public:
    double average(vector<int>& salary) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        double sum=0;
        int n=salary.size();
        for(int i=0;i<n;i++){
            sum+=salary[i];
            if(salary[i]>mx) mx=salary[i];
            if(salary[i]<mn) mn=salary[i];
        }
        sum=sum-(mn+mx);
        return sum/(n-2);
    }
};