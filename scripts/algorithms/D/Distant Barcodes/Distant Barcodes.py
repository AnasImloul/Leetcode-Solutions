# Runtime: 1287 ms (Top 5.56%) | Memory: 16.2 MB (Top 67.41%)

import heapq

class Solution:

    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        barcodes_counter = Counter(barcodes)
        if len(barcodes_counter) == len(barcodes):
            return barcodes

        barcodes_heapq = [ (-c, b) for b, c in barcodes_counter.items() ]
        heapq.heapify(barcodes_heapq)

        idx, prev_count, prev_barcode = 0, 0, 0
        while barcodes_heapq:
            (curr_count, curr_barcode) = heapq.heappop(barcodes_heapq)

            barcodes[idx] = curr_barcode
            idx += 1
            curr_count += 1

            if prev_count:
                heapq.heappush(barcodes_heapq, (prev_count, prev_barcode))

            prev_count, prev_barcode = curr_count, curr_barcode

        return barcodes
