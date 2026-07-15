class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd{1}, even{2}, cnt{1}, even_sum{2}, odd_sum{1};
        while(cnt<n){
            odd += 2;
            even += 2;
            odd_sum += odd;
            even_sum += even;
            cnt++;
        }
        return __gcd(even_sum, odd_sum);
    }
};