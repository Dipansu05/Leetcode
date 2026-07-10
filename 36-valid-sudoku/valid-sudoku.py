class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for col in range(9):
            seen = set()
            for i in range(9):
                if board[i][col] == ".":
                    continue
                if board[i][col] in seen:
                    return False
                seen.add(board[i][col])

        for row in range(9):
            seen = set()
            for i in range(9):
                if board[row][i] == "." :
                    continue
                if board[row][i] in seen :
                    return False
                seen.add(board[row][i])

        for sq in range(9):
            seen = set()
            for i in range (3):
                for j in range (3):
                    r = (sq // 3) * 3 + i
                    c = (sq % 3) * 3 + j
                    if board[r][c] == ".":
                        continue
                    if board[r][c] in seen:
                        return False
                    seen.add(board[r][c])

        return True