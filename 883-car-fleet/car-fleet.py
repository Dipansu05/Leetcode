class Solution:
    def carFleet(self, target: int, pos: List[int], speed: List[int]) -> int:
        pair = [(p,s) for p,s in zip(pos, speed)]
        pair.sort(reverse=True)
        fleets=1
        prevtime = (target-pair[0][0]) / pair[0][1]
        for i in range(1, len(pair)):
            curtime = (target-pair[i][0]) / pair[i][1]
            if curtime > prevtime:
                fleets += 1
                prevtime = curtime

        return fleets