class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        temp = sorted(arr)
        rank = {}
        r = 1
        for i in temp:
            if i not in rank:
                rank[i] = r
                r += 1

        for i in range(len(arr)):
            arr[i] = rank[arr[i]]
        
        return arr