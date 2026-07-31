class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        l=0
        r=(rows*cols)-1
        while l <= r:
            mid = l + (r-l) // 2
            rx = mid//cols
            cx = mid%cols
            if matrix[rx][cx] == target:
                return True
            elif matrix[rx][cx] > target:
                r = mid - 1
            else:
                l = mid+1

        return False