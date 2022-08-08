class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        #accumulative count
        #+1 when > 8, -1 when less than 8. 
        #find strictly increasing length.
        
        p = [] #number of tiring days vs not
        c = 0
        for e in hours:
            if e > 8:
                c +=1
            else:
                c-=1
            
            p.append(c)
            
            
        
        #for every moment: we want earliest moment which could be positive overall tiring days.
        a = []
        #a is sorted by tiringnes. At day 8 have -2, want earliest point that could get us to at least 1.
        #so up until that point we have -3, -4, etc, and we want earliest out of it to get longest well performing interval. Which is when prefix comes in.
        
        a1 =[]
        for i in range(len(p)):
            a.append([p[i], i])
            a1.append(p[i])
        
        a1.sort() #bisectable list
        a.sort()
        
        prefix = []
        currearly = float('inf')
        for t, day in a:
            currearly = min(currearly, day)
            prefix.append(currearly)
        
        
        res = 0
        
        # print(p)
        
        for i in range(len(hours)):
            if p[i] > 0:
                res = max(res, i + 1) 
            
            else:
                #find earliest 
                #value must be less than -1-p[i] 
                loc = bisect_right(a1, -1+p[i]) #bisect right means anything before this is less than or equals to
                
                
                
                if loc == 0: #the rightmost place to put it is at the beginning...
                    
                    continue
                
                
                else:
                    earliest = prefix[loc - 1]
                    
                    if earliest >= i: continue
                    
                    interval = i - earliest #notice: we're not including the starting index, since its also technically being removed!

                    # print("From day", earliest, "to", i)
                    
                    res = max(res, interval)
        
        
        
        return res
        
        
        
        
