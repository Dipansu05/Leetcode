class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            rem = target - numbers[i]
            l = i + 1
            r = len(numbers) - 1
            while l <= r:
                mid = l + (r-l) // 2
                if numbers[mid] == rem:
                    return [i+1, mid+1]
                elif numbers[mid] > rem:
                    r = mid - 1
                else:
                    l = mid + 1

        return []