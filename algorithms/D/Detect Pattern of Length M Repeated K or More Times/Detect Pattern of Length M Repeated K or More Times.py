class Solution(object):
    def containsPattern(self, arr, m, k):
        """
        :type arr: List[int]
        :type m: int
        :type k: int
        :rtype: bool
        """
        w_start=0
        w_end=w_start+m
        n=len(arr)
        count=1
        while (w_end < n):
            if (arr[w_start:w_end] == arr[w_end:w_end+m]): 
                count+=1
                if count >= k:
                    return True
                w_start=w_end
                w_end+=m
                #if found the matching window, 
                #increments both by the size of window(m)
                #otherwise increment by 1
            else:
                count = 1
                w_start+=1
                w_end+=1
        return False
