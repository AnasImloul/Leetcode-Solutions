import heapq
class Solution(object):
    def eatenApples(self, apples, days):
        """
        :type apples: List[int]
        :type days: List[int]
        :rtype: int
        """
        heap = [(days[0], apples[0])]
        heapq.heapify(heap)
        day = 0
        rtn = 0
        while heap or day < len(days):
            # print(heap, day)
            apple = 0
            if heap :
                cnt, apple = heapq.heappop(heap)
                while heap and cnt <= day and apple > 0:
                    cnt, apple = heapq.heappop(heap)
            if apple > 0 and cnt > day  :
                rtn +=1
            day +=1
            if apple >  1 and cnt > day:
                heapq.heappush(heap, (cnt, apple-1))
            if day < len(days) and apples[day] > 0 :
                heapq.heappush(heap, (day +days[day], apples[day]))
        return rtn 