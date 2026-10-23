class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        res = ""
        M = {}
        S = []
        for c in s:
            M[c] = M.get(c,0)+1
        seen = set()
        for c in s:
            M[c] -= 1
            if c in seen:
                continue
            while S and c < S[-1] and M[S[-1]] > 0:
                seen.discard(S[-1])
                S.pop()
            S.append(c)
            seen.add(c)
        while S:
            res = S[-1] + res
            S.pop()
        return res