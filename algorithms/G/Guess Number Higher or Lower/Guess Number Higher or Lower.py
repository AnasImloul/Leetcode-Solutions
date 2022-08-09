class Solution:
    def guessNumber(self, n: int) -> int:
        l=1
        h=n
        while l<=h:
            mid=(l+h)//2
            x =guess(mid)
            if(x==0):
                return mid
            elif(x==1):
                l = mid+1
            else:
                h = mid-1
