# Runtime: 32 ms (Top 93.2%) | Memory: 16.18 MB (Top 93.2%)

class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        # Calculate the max time for a pig to test buckets...
        # Note that, max time will not be (minutesToTest / minutesToDie)...
        # Thinking about all pigs drinking all buckets at last, but no one died immediately, so the poison bucket is the last bucket...
        max_time = minutesToTest / minutesToDie + 1
        # Initialize the required minimum number of pigs...
        req_pigs = 0
        # To find the minimum number of pigs, find the minimum req_pigs such that Math.pow(max_time, req_pigs) >= buckets...
        while (max_time) ** req_pigs < buckets:
            # Increment until it will be greater or equals to bucket...
            req_pigs += 1
        # Return the required minimum number of pigs...
        return req_pigs