class Solution(object):
    def longestCommonPrefix(self, strs):
        temp=strs.pop(strs.index(max(strs,key=len)))
        count=0
        while True:
            for i in strs:
                if temp in i[0:len(temp)]:
                    count+=1
                else:
                    continue
            if count==len(strs):
                return temp
                break
            else:
                count=0
                if temp=='':
                    return temp
                else:
                    temp=temp[0:len(temp)-1]
