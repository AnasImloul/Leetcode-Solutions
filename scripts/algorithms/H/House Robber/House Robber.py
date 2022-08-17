class Solution:
    def rob(self, nums: List[int]) -> int:
        # [rob1,rob2,n,n+1]
        # 1 | 2 | 3 | 1  
   #index 0   1   2   3
        # so upto last index it depends on previous 2 values :
    # here upto 2nd index max rob is 1+3=4; not choosing adjacent element 2
    # and upto 1st index  max rob is 2 ; not choosing any adjacent elements
    # so at 3rd index it depend on prev rob value and 1st index rob value+last value
    # i.e max(2+(val at last index),4)
        rob1=0;rob2=0;
        for i in nums:
            temp=max(rob1+i,rob2);
            rob1=rob2;
            rob2=temp;
        return rob2;

