class Solution:
    def sumGame(self, num: str) -> bool:
        n=len(num)
        diff=0
        cnt=0
        hf=n//2
        for i in range(n):
            if num[i]!='?':
                diff=diff+(int(num[i]) if i<hf else -int(num[i]))
            else:
                cnt=cnt+(1 if i<hf else -1)
        if cnt<0:
            cnt=abs(cnt)
            diff=-diff
        al=(cnt+1)//2
        bb=cnt-al
        mx=diff+al*9
        mn=diff
        if mx>0 or mn>0 or abs(mn)>bb*9 or abs(mx)>bb*9:
            return True
        return False