class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        arr.sort()
        count = 0
        for i in range(0, len(arr)-2):
            rem_sum = target - arr[i]
            hash_map = {}
            for j in range(i+1, len(arr)):
                if arr[j] > rem_sum:
                    break
                if rem_sum - arr[j] in hash_map:
                    count = count + hash_map[rem_sum-arr[j]]
                # update the hash_map
                hash_map[arr[j]] = hash_map.get(arr[j], 0) + 1
        return count % 1000000007
