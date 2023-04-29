class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        
        # sort queries from small to large
        q = deque(sorted([(x, i) for i, x in enumerate(queries)]))
        
        # answer to queries, initial state set to -1
        ans = [-1] * len(queries)

        # sort intervals by low, high and size
        ivals = deque(sorted([(a, b, b - a + 1) for a, b in intervals]))
        
        # available intervals
        cands = []

        
        while q:
            x, i = q.popleft()
            
            # if lower bound of intervals on the top of stack <= current query
            while ivals and x >= ivals[0][0]:
                a, b, c = ivals.popleft()
                # if higher bound of intervals also meets the requirements
                # if not then discard the interval
                if x <= b:
                    heappush(cands, (c, b, a))
            
            # udpate available intervals by removing old ones which no longer has a eligible higher bound
            while cands:
                c, b, a = heappop(cands)
                if x <= b:
                    ans[i] = c
                    heappush(cands, (c, b, a))
                    break

        return ans