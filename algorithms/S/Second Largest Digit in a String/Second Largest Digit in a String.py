class Solution:
    def secondHighest(self, s: str) -> int:
        s=set(s)
        a=[]
        for i in s:
            if i.isnumeric() :
                a.append(int(i))
        a.sort()
        if len(a)<2:
            return -1
        return a[len(a)-2]
