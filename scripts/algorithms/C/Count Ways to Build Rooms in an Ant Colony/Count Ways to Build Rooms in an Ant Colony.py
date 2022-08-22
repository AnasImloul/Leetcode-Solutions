# Runtime: 4732 ms (Top 93.33%) | Memory: 177.5 MB (Top 6.67%)
class Solution:
    def waysToBuildRooms(self, prevRoom: List[int]) -> int:
        mod = 10 ** 9 + 7
        n = len(prevRoom)

        mod_inverses = [1] * (n + 1)
        factorials = [1] * (n + 1)
        inverse_factorials = [1] * (n + 1)

        for x in range(2, n + 1): # Precompute all factorials and inverse factorials needed in O(1) time each
            mod_inverses[x] = mod - mod // x * mod_inverses[mod % x] % mod
            factorials[x] = (x * factorials[x - 1]) % mod
            inverse_factorials[x] = (mod_inverses[x] * inverse_factorials[x - 1]) % mod

        children = collections.defaultdict(list) # Convert parent list to children lists
        for i, x in enumerate(prevRoom[1:], 1):
            children[x].append(i)

        def postorder(curr: int) -> Tuple[int, int]:
            if curr not in children: # Leaf has ways, size both 1
                return 1, 1
            tot_size = 1
            tot_ways = 1
            for child in children[curr]:
                ways, size_of = postorder(child)
                tot_ways *= ways * inverse_factorials[size_of]
                tot_size += size_of
            tot_ways *= factorials[tot_size-1]
            return tot_ways % mod, tot_size

        return postorder(0)[0]