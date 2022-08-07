class Solution(object):
    def removeDuplicates(self, nums):
        n=len(nums)
        if n==2:
            return 2
        if n==0:
            return 0
        if n==1:
            return 1
        same=0
        start=-1
        end=-1
        i=0
        while i<n-1:
            if nums[i]==nums[i+1] and same==0:
                same=1
                start=i+2
                i+=1
                continue
            while i<n-1 and nums[i]==nums[i+1] and same==1:
                end=i+1
                i+=1
            i+=1
            if start!=-1 and end!=-1:
                no_of_shifts=end-start+1
                while i<n:
                    nums[i-no_of_shifts]=nums[i]
                    i+=1
                n=n-no_of_shifts
                i=start
            start=-1
            end=-1
            same=0
            
        return n
		```