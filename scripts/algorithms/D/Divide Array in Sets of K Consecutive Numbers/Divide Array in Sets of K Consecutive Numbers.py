// Runtime: 304 ms (Top 99.22%) | Memory: 27.60 MB (Top 95.6%)

class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        # if we see x, we expect to see x+1 later
        #   and then x+2 after that
        #   and then x+3 after that

        # so maybe we can enqueue (x+1, k-2)  === (next number expected, count after x+1)
        #   e.g. k == 2: find x, enqueue (x+1, 0)
        
        # for each x:
        #   if front of queue has x, pop it. Re-enqueue with rem-1 if rem, else we finished a length k sequence
        #   if front of queue has x' < x, we have a gap. return False
        #   otherwise we found the start of a new sequence: append (x+1, k-2)
        #     meaning we found x (1), we're looking for x+1 (another 1), and after that we should find another k-2 numbers

        if k == 1: return True # length 1 sequences are trivial

        nums.sort()
        q = deque()
        for n in nums:
            if not q or q[0][0] > n:
                q.append((n+1, k-2))
            elif q[0][0] == n:
                _, rem = q.popleft()
                if rem:
                    q.append((n+1, rem-1))
                # else: end of len k sequence
            else:
                return False # found n > next expected, so we can't complete an earlier sequence

        if q:
            return False # expected at least one more element to finish a sequence
        else:
            return True
