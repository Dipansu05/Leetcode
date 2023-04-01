class Solution {
public:
int binarysearch(vector<int>& arr,int s,int e, int t){
    int mid,ans=0;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==t)
        return mid;
        else if(arr[mid]<t)
        s=mid+1;
        else 
        e=mid-1;
    }
    return -1;
}
    int search(vector<int>& arr, int t) {
        if(arr[0]==t)
    return 0;
    int i =1;
    int n=arr.size();
    while(i<n&&arr[i]<=t){
        i=i*2;
    }
    return binarysearch(arr,i/2,min(i,n-1),t);
  }
};