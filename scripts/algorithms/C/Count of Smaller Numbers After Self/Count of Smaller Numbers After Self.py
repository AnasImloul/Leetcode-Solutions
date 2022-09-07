# Runtime: 6019 ms (Top 15.52%) | Memory: 35.5 MB (Top 33.31%)
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # build the binary indexed tree
        num_buckets = 10 ** 4 + 10 ** 4 + 1 # 10**4 negative + 10**4 positive numbers + bucket at 0
        tree = [0] * (num_buckets + 1) # add 1 because binary indexed tree data starts at index 1

        result = [0] * len(nums)

        # iterate from right to left
        for result_index in range(len(nums) - 1, -1, -1):
            n = nums[result_index]
            # add 10**4 to n to account for negative numbers
            i = n + 10 ** 4

            # convert to 1-based index for the tree
            i += 1
            # perform range sum query of buckets [-inf, n-1], where n is current number
            # because we want n - 1 for range sum query of [-inf, n-1], not n, subtract 1 from i:
            i -= 1

            val = 0
            while i != 0:
                val += tree[i]
                # get parent node by subtracting least significant set bit
                i -= i & -i

            result[result_index] = val

            # update the binary indexed tree with new bucket
            i = n + 10 ** 4
            i += 1
            while i < len(tree):
                tree[i] += 1
                # get next node to update by adding the least significant set bit
                i += i & -i

        return result