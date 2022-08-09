class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        lis=deque([])
        prev_popped=-1
        for i in range(len(nums)):
            if(nums[i]==key):
                lis.append(i)
        ans=[]
        for i in range(len(nums)):
            if(len(lis)>0 and lis[0]<i):
                prev_popped = lis.popleft()
            if(prev_popped!=-1 and (i-prev_popped) <=k):
                ans.append(i)
            elif(len(lis)>0 and (lis[0]-i)<=k):
                ans.append(i)
        return ans
