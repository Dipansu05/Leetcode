class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       int left = 0;
        int right = letters.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left == letters.size() ? letters[0] : letters[left];
    }
};