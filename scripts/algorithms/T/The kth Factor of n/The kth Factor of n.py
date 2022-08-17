class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        start=[1]
        end=[n]
        for i in range(2,math.ceil(math.sqrt(n))+1):
            if n%i==0:
                start.append(i)
                if i!=n//i:
                    end.append(n//i)
        start=sorted(set(start).union(set(end)))
        if k<=len(start):
            return start[k-1]
        else:
            return -1
