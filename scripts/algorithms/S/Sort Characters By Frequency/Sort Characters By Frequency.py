class Solution:
    def frequencySort(self, s: str) -> str:
        di = Counter(s)
        #it wont strike immediately that this is a heap kind of question.
        heap = []
        heapq.heapify(heap)
        for key,val in di.items():
            heapq.heappush(heap,(-1*val,key))
        # n = len(s)
        res = ""
        # print(heap)
        while(len(heap)):
            val,ch = heapq.heappop(heap)
            res+=(ch*(-1*val))
        return res
