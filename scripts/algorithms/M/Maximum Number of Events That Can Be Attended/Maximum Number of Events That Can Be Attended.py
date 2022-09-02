# Runtime: 1160 ms (Top 93.22%) | Memory: 61.6 MB (Top 51.45%)
class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events = sorted(events, key=lambda x: x[0])
        current_day = 0
        min_heap = []
        event_id = 0
        total_number_of_days = max(end for start, end in events)
        total_events_attended = 0
        #total_number_of_days+1 because I want to include the last day
        for day in range(1, total_number_of_days+1):

            #Add all the events that can be started on that day
            while event_id < len(events) and events[event_id][0] == day:
                heapq.heappush(min_heap, events[event_id][1])
                event_id+=1

            #while there is something in heap and the event should have been completed before the current day
            #remove those evenets and consider them not attended
            while min_heap and min_heap[0] < day :
                heapq.heappop(min_heap)

            #if theere is an event present in heap
            #lets mark 1 of those events as complted today and add it to
            #total_events_attended

            if min_heap:
                heapq.heappop(min_heap)
                total_events_attended+=1
        return total_events_attended
