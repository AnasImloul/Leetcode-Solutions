class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        '''
            执行用时：24 ms, 在所有 Python 提交中击败了59.63%的用户
            内存消耗：13 MB, 在所有 Python 提交中击败了58.72%的用户
        '''
        arr = sorted(arr) # 排序
        for i in range(len(arr) - 1): # 只要搜寻 n - 1 个，因为最后一个数不会有倍数出现
            l = 0
            r = len(arr) - 1
            while (l <= r):
                mid = int((l + r) / 2) # 目前位置
                val1 = arr[mid] # 目前位置的数值
                val2 = arr[i] * 2 # 要寻找的目标
                if(val1 == val2 and mid != i): # arr[mid] 必須和 arr[i] * 2 且不同位置
                    return True
                elif(val2 < val1): # 目标在目前位置的左边，所以要往左边找
                    r = mid - 1
                else: # 目标在目前位置的右边，所以要往右边找
                    l = mid + 1
        return False
