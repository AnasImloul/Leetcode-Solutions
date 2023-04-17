class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        sz, hashMap = len(nums), defaultdict(int)
        ans = curPairs = temp = left = right = 0
        for right in range(sz):
            hashMap[nums[right]] += 1
            curPairs += (hashMap[nums[right]] - 1)
            while curPairs >= k and left < right:
                ans += (sz - right)
                hashMap[nums[left]] -= 1
                curPairs -= hashMap[nums[left]]
                left += 1
        return ans