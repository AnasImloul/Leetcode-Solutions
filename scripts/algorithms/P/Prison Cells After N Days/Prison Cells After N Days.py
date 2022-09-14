# Runtime: 85 ms (Top 14.83%) | Memory: 14 MB (Top 28.83%)
class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        patternMatch=defaultdict(int) # pattern match
        totalPrisons=8 # totalPrisons
        cells= [ str(c) for c in (cells)] # into char type
        for d in range(1,n+1):
            tempCell=[]
            tempCell.append('0') # left corner case
            for c in range(1,totalPrisons-1):
                if (cells[c-1]=='1' and cells[c+1]=='1') or (cells[c-1]=='0' and cells[c+1]=='0'):
                    tempCell.append('1') # insert 1 if first condition met
                else:
                    tempCell.append('0') # otherwise 0
            tempCell.append('0') # right corner case
            cells=tempCell # update cells
            pattern= ''.join(tempCell) # insert pattern in hashtable
            if pattern in patternMatch: # if there is a match
                day=patternMatch[pattern]
                remainder= (n%(d-1))-1 # take modulo
                match= list(patternMatch.keys())[remainder] # find key
                return [ int(m) for m in match] # return
            patternMatch[pattern]=d # assign day
        return [ int(c) for c in (cells)] # return