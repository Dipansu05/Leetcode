class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        self.memo = [0] * (n+1)
        return self.canWin(n)

    def canWin(self,n):
        if n==0:
            return False
        if self.memo[n] != 0:
            return self.memo[n] == 1
        win = False
        i = 1
        while i*i <= n:
            if not self.canWin(n-i*i):
                win = True
                break
            i += 1
        self.memo[n] = 1 if win else 2
        return win