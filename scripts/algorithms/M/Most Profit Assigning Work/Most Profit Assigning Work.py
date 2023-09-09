# Runtime: 489 ms (Top 13.7%) | Memory: 19.08 MB (Top 98.5%)

class Solution:
    #Time-Complexity: O(n + nlogn + n + mlog(n)) -> O((n+m) *logn)
    #Space-Complexity: O(n)
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        #Approach: First of all, linearly traverse each and every corresponding index
        #position of first two input arrays: difficulty and profit to group each
        #item by 1-d array and put it in separate 2-d array. Then, sort the 2-d array
        #by increasing difficulty of the job! Then, for each worker, perform binary
        #search and consistently update the max profit the current worker can work and
        #earn! Add this value to answer variable, which is cumulative for all workers!
        #this will be the result returned at the end!
        arr = []
        for i in range(len(difficulty)):
            arr.append([difficulty[i], profit[i]])
        #sort by difficulty!
        arr.sort(key = lambda x: x[0])
        #then, I need to update the maximum profit up to each and every item!
        maximum = float(-inf)
        for j in range(len(arr)):
            maximum = max(maximum, arr[j][1])
            arr[j][1] = maximum
        ans = 0
        #iterate through each and every worker!
        for w in worker:
            bestProfit = 0
            #define search space to perform binary search!
            L, R = 0, len(arr) - 1
            #as long as search space has at least one element to consider or one job,
            #continue iterations of binary search!
            while L <= R:
                mid = (L + R) // 2
                mid_e = arr[mid]
                #check if current job has difficulty that is manageable!
                if(mid_e[0] <= w):
                    bestProfit = max(bestProfit, mid_e[1])
                    #we still need to search right and try higher difficulty
                    #jobs that might yield higher profit!
                    L = mid + 1
                    continue
                else:
                    R = mid - 1
                    continue
            #once we break from while loop and end binary search, we should have
            #found bestProfit for current worker performing task that is manageable!
            ans += bestProfit
        return ans