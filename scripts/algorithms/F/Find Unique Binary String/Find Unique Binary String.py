class Solution(object):
    def findDifferentBinaryString(self, nums):
        ans='';
        for i,num in enumerate(nums):
            ans+= '1' if(num[i]=='0') else '0'       #ternary if else
			#ans+= str(1- int(num[i]));              # Alternate: cast to string & 1-x to flip
        return ans;
