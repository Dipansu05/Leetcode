//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        
        vector<int> ans;
        ans.push_back(1);
        for(int x=2;x<=N;x++){
            int c=0;
            for(int i=0;i<ans.size();i++){
                int v=ans[i]*x+c;
                ans[i]=v%10;
                c=v/10;
            }
            while(c!=0){
                ans.push_back(c%10);
                c/=10;
            }
        }
       
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends