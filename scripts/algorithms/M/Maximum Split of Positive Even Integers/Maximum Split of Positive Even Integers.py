# Runtime: 1817 ms (Top 5.05%) | Memory: 26.8 MB (Top 41.50%)
class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        l=[]
        if finalSum%2!=0:
            return l
        else:
            s=0
            i=2 # even pointer 2, 4, 6, 8, 10, 12...........
            while(s<finalSum):
                s+=i #sum
                l.append(i) # append the i in list
                i+=2
            if s==finalSum: #if sum s is equal to finalSum then no modidfication required
                return l
            else:
                l.pop(l.index(s-finalSum)) #Deleting the element which makes s greater than finalSum
            return l