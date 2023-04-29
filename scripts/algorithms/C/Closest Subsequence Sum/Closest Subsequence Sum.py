class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:

        # When goal 0 we can just choose no elements 
        if goal == 0: return 0

        n = len(nums)
        mid = n // 2
        # Split the list in 2 parts and then find all possible subset sums 
        # T = O(2^n/2) to build all subset sums
        leftList = nums[:mid]
        leftSums = []
        rightList = nums[mid:]
        rightSums = []

        # T = O(2^n/2) to build all subset sums (we only consider half list)
        def buildSubsetSums(usedNums, numsToChooseFrom, ind, storeIn):
            if ind == len(numsToChooseFrom):
                # We also keep elements with sum 0 to deal with cases like this where we don't select nums
                # List: [1,2,3], Target: -7 (choosing no elements will give a sum close to goal)
                # We can also have cases where we want to take only 1 element from the list
                # so sum 0 for left and right list needs to be an option
                storeIn.append(sum(usedNums))
                return 

            usedNums.append(numsToChooseFrom[ind])
            buildSubsetSums(usedNums, numsToChooseFrom, ind+1, storeIn)
            usedNums.pop()
            buildSubsetSums(usedNums, numsToChooseFrom, ind+1, storeIn)


        buildSubsetSums([], leftList, 0, leftSums)
        buildSubsetSums([], rightList, 0, rightSums)
        # 2^n/2 log(2^n/2) = n/2 * 2^n/2 time to sort
        rightSums.sort()

        diff = float('inf')

        # Loop runs 2^n/2 times and inside binary search tale n/2 time 
        # So total time is n/2 * 2^n/2
        for leftSum in leftSums:
            complement = goal - leftSum
            # Bisect left takes log(2^n/2) = n/2 search time
            idx = bisect.bisect_left(rightSums, complement)

            for i in [idx - 1, idx, idx + 1]:
                if 0 <= i < len(rightSums):
                    finalSum = leftSum + rightSums[i]
                    diff = min(diff, abs(goal - finalSum))
        
        # Over all time complexity is - n/2 * 2^n/2
        # 1. Making subset sums will take - 2^n/2
        # 2. Sorting right list takes - 2^n/2 * n/2
        # 3. Iterating one list and finding closest complement in other 
        # takes n/2 * 2^n/2
        # Space will be O(n/2) for the list and call stack for building subset 
        return diff

