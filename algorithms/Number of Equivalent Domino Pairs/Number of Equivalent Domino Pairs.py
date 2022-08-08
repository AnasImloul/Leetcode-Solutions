import math
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d=dict()
        for i in dominoes:
            i.sort()            #Just to make everything equal and comparable
            if(tuple(i) in d.keys()):   #In python, lists are unhashable so converted the list into tuples
                d[tuple(i)]+=1
            else:
                d[tuple(i)]=1
        count=0
        for x,y in d.items():
            if(y>1):
				count+=y*(y-1)//2        #To check the number of pairs, if 2 elements pairs is 1,if 3 pair is 3 and so                                                                     on.....formula is n*n-1/2
        return count
                


