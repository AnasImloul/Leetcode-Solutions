class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        start = customers[0][0]
        end = start + customers[0][1]
        total_wait = end - start
        for c in customers[1:]:
            start = c[0]
            if start <= end:
                end += c[1]
                total_wait = total_wait + end - start
            else:
                end = c[0]+c[1]
                total_wait += c[1]
        return total_wait/len(customers)
            
    
    
    
