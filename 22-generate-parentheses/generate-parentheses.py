class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []
        def solve(temp: str,open_count: int,close_count: int):
            if len(temp)==2*n:
                res.append(temp)
                return
            
            if open_count<n:
                solve(temp+"(", open_count+1,close_count)
            if close_count < open_count:
                solve(temp+")", open_count, close_count+1)

        solve("", 0, 0)
        return res