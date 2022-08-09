from sortedcontainers import SortedList

class MKAverage:

    MAX_NUM = 10 ** 5
    def __init__(self, m: int, k: int):
        
        self.m = m
        self.k = k
        
        # sorted list
        self.sl = SortedList([0] * m)
		# sum of k smallest elements
        self.sum_k = 0
		# sum of m - k smallest elements
        self.sum_m_k = 0
        
        # queue for the last M elements if the stream
        self.q = deque([0] * m)
        
    def addElement(self, num: int) -> None:
        # Time: O(logm)
		
        m, k, q, sl = self.m, self.k, self.q, self.sl            
            
        # update q
        q.append(num)
        old = q.popleft()
        
        # remove the old num
        r = sl.bisect_right(old)
		# maintain sum_k
        if r <= k:
            self.sum_k -= old
            self.sum_k += sl[k]
		# maintain sum_m_k
        if r <= m - k:
            self.sum_m_k -= old
            self.sum_m_k += sl[m-k]
        # remove the old num
        sl.remove(old)
        
        # add the new num
        r = sl.bisect_right(num)
        if r < k:
            self.sum_k -= sl[k-1]
            self.sum_k += num
        if r < m - k:
            self.sum_m_k -= sl[m - k - 1]
            self.sum_m_k += num
        
        sl.add(num)
            
        return

    def calculateMKAverage(self) -> int:
		# Time: O(1)
        if self.sl[0] == 0:
            return -1
        return (self.sum_m_k - self.sum_k) // (self.m - self.k * 2)
