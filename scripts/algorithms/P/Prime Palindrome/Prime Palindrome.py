# Runtime: 4865 ms (Top 9.52%) | Memory: 16.4 MB (Top 7.94%)
class Solution:
    def primePalindrome(self, n: int) -> int:
        if n<3:return 2
        #generating palindrome less than 10**8
        l=[""]+[*"1234567890"]
        for i in l:
            if len(i)<7:
                for j in "1234567890":
                    l+=[j+i+j]
        #finding prime from generated palindrome
        q=[]
        for i in l[2:]:
            if i[0]!="0":
                i=int(i)
                t=i%2
                if t:
                    for j in range(3,int(i**.5)+1,2):
                        if i%j==0:
                            t=0
                            break
                if t:q+=[i]
        q.sort()
        q+=[100030001]
        return q[bisect_left(q,n)]