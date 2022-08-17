from collections import defaultdict
import heapq

class Solution:
    def largestValsFromLabels(
        self, values: list[int], labels: list[int], numWanted: int, useLimit: int
    ) -> int:

        # Add labels and values into the heap
        heap = [(-value, label) for value, label in zip(values, labels)]
        heapq.heapify(heap)

        # Initialize the hashmap
        used = defaultdict(int)

        # Initialize the result
        res = 0

        # Iterate until we have used a certain number or the heap is empty
        while numWanted > 0 and heap:

            # Pop a label and its value from the heap
            value, label = heapq.heappop(heap)

            # If we can use such label
            if used[label] < useLimit:

                # Add its value to the result
                res += -value

                # Increment its count in the hashmap
                used[label] += 1

                # Decrement the number of numbers we still want
                numWanted -= 1

        return res
