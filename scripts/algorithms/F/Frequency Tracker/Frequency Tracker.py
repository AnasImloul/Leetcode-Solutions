// Runtime: 474 ms (Top 92.66%) | Memory: 80.20 MB (Top 8.86%)

from collections import defaultdict
class FrequencyTracker:

    def __init__(self):
        self.count = defaultdict(int)
        self.freq = defaultdict(set)
        
    def add(self, number: int) -> None:
        prevCount = self.count[number] 
        # delete number if it is already present in the set at its current freq
        if number in self.freq[ prevCount ]:
            self.freq[self.count[number]].remove(number)
        
        #increment count or ocurence of number
        self.count[number] += 1
        newCount = prevCount + 1 
        #add number in the set at newCount
        self.freq[newCount].add(number)
        
    def deleteOne(self, number: int) -> None:
        # delete number if it is already present in the set at its current freq
        if number in self.freq[ self.count[number] ]:
            self.freq[self.count[number]].remove(number)
        
        if self.count[number]: # if number is alredy present, decrement its count by 1
            self.count[number] -= 1
            if self.count[number] == 0: # if its become remove from count dict 
                del self.count[number]
            else: # otherwise add the number in the set at newCount
                newCount = self.count[number]
                self.freq[newCount].add(number) 
    
    def hasFrequency(self, frequency: int) -> bool:
        # return true if set is exist(i.e length > 0) at frequency, otherwise false 
        return self.freq[frequency]
        
