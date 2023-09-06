# Runtime: 931 ms (Top 66.6%) | Memory: 45.16 MB (Top 22.2%)

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        #we ADD flowers in the order in which they start, but we remove them in the order they 
        #end.  For this reason, we sort the flowers by starting time but put them in a heap, 
        #in which we remove them by ending time
        starts = sorted(flowers) #keep flowers untouched in case array should be constant
        blooming = [] #heap of active flowers
        answer = [-1] * len(people) #output array
        hours = [(people[i], i) for i in range(len(people))] #the people, ordered and indexed by their time
        hours.sort()

        i = 0 #going through starts
        for hour, person in hours:
            #add all flowers that have started
            while i < len(starts) and starts[i][0] <= hour:
                heappush(blooming, (starts[i][1], starts[i][0]))
                i += 1
            #now remove all flowers that have ended.  Note that we only care about the absolute smallest, 
            #and in python minheaps, that is always the first element - even if no other element's order 
            #is guaranteed
            while blooming and blooming[0][0] < hour: #as long as the soonest to end blooming flower hasn't already stopped
                heappop(blooming)
            answer[person] = len(blooming)
        
        return answer