class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> result;
        long int temp = rowIndex;
        int a=rowIndex, b=1;
        for(int i=0;i<rowIndex+1;i++){
            if(i==0 || i==rowIndex) result.push_back(1);
            else {
                result.push_back(temp);
                temp = (temp*(--a))/++b; 
            }
        }
        return result;
    }
};