class Solution:
    def longestValidParentheses(self, s: str) -> int:
        right = left = maxLen = 0
        for c in s:
            if c == '(':
                left += 1
            else:
                right += 1
            if left == right:
                maxLen = max(maxLen, 2*right)
            elif right > left:
                right = left = 0

        right = left = 0
        
        for c in reversed(s):
            if c == '(':
                left += 1
            else:
                right += 1
            if left == right:
                maxLen = max(maxLen, 2*left)
            elif left > right:
                left = right = 0
        

        return maxLen