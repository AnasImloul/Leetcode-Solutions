# Runtime: 3421 ms (Top 39.22%) | Memory: 51.8 MB (Top 96.08%)
class Solution:
    def smallestMissingValueSubtree(self, parents: List[int], nums: List[int]) -> List[int]:
        ans = [1] * len(parents)
        if 1 in nums:
            tree = {}
            for i, x in enumerate(parents):
                tree.setdefault(x, []).append(i)

            k = nums.index(1)
            val = 1
            seen = set()

            while k != -1:
                stack = [k]
                while stack:
                    x = stack.pop()
                    seen.add(nums[x])
                    for xx in tree.get(x, []):
                        if nums[xx] not in seen:
                            stack.append(xx)
                            seen.add(nums[xx])
                while val in seen: val += 1
                ans[k] = val
                k = parents[k]
        return ans