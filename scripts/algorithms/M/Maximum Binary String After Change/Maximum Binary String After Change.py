# Runtime: 128 ms (Top 57.69%) | Memory: 15.4 MB (Top 69.23%)
class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        zero = binary.count('0') # count number of '0'
        zero_idx = binary.index('0') if zero > 0 else 0 # find the index of fist '0' if exists
        one = len(binary) - zero_idx - zero # count number of '1' (not including leading '1's)
        return f"{binary[:zero_idx]}{'1'*(zero-1)}{'0'*min(zero, 1)}{'1'*one}"