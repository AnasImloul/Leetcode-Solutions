from sortedcontainers import SortedList
class Solution:
    def goodTriplets(self, A: List[int], B: List[int]) -> int:
        # Index of a (from A) in B.
        pos = [0] * len(A)               
        for idx, b in enumerate(B):
            pos[b] = idx
        
        # Build pre_a[i]: number of elements on a[i]'s left in both A and B.
        # pos_in_b: sorted indexes (in B) of all the visited elements in A.
        pos_in_b, pre_a = SortedList([pos[A[0]]]), [0]      
        for a in A[1:]:       
            pos_in_b.add(pos[a])
            pre_a.append(pos_in_b.bisect_left(pos[a]))
    
        # Build suf_a[i]: number of elements on a[i]'s right in both A and B.
        pos_in_b, suf_a = SortedList([pos[A[-1]]]), [0]
        for a in reversed(A[:len(A)-1]):
            idx = pos_in_b.bisect(pos[a])
            suf_a.append(len(pos_in_b) - idx)
            pos_in_b.add(pos[a])
        suf_a.reverse()
        
        # Sum up all unique triplets centered on A[i].
        ans = 0
        for x, y in zip(pre_a, suf_a):
            ans += x * y
        return ans
