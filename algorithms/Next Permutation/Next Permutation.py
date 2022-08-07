class Solution:
    def nextPermutation(self, nums) -> None:
        firstDecreasingElement = -1
        toSwapWith = -1
        lastIndex = len(nums) - 1

        # Looking for an element that is less than its follower
        for i in range(lastIndex, 0, -1):
            if nums[i] > nums[i - 1]:
                firstDecreasingElement = i - 1
                break

        # If there is not any then reverse the array to make initial permutation
        if firstDecreasingElement == -1:
            for i in range(0, lastIndex // 2 + 1):
                nums[i], nums[lastIndex - i] = nums[lastIndex - i], nums[i]
            return

        # Looking for an element to swap it with firstDecreasingElement
        for i in range(lastIndex, 0, -1):
            if nums[i] > nums[firstDecreasingElement]:
                toSwapWith = i
                break

        # Swap found elements
        nums[firstDecreasingElement], nums[toSwapWith] = nums[toSwapWith], nums[firstDecreasingElement]

        # Reverse elements from firstDecreasingElement to the end of the array
        left = firstDecreasingElement + 1
        right = lastIndex
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
