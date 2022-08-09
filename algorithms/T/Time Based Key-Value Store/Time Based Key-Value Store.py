class TimeMap:

    def __init__(self):
        self.dict = {}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.dict:
            self.dict[key] = ([], [])
            self.dict[key][0].append(value)
            self.dict[key][1].append(timestamp)
        else:
            self.dict[key][0].append(value)
            self.dict[key][1].append(timestamp)
    
    
    def bsearch(self, nums, target):
        beg = 0
        end = len(nums)-1
        lastIndex = len(nums)-1
        
        while beg<=end:
            mid = (beg+end)//2
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                end = mid-1
            elif target > nums[mid]:
                beg = mid+1
        
        
        if target < nums[mid] and mid == 0:
            return -1
        if target > nums[mid]:
            return mid
        return mid-1
            
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.dict:
            return ""
        
        index = self.bsearch(self.dict[key][1], timestamp)
        return self.dict[key][0][index] if 0 <= index < len(self.dict[key][0]) else ""
    


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
