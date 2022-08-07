class Solution:
    def convertToBase7(self, num: int) -> str:
        if num==0: return '0'
        flag = 1 if num>=0 else 0
        output = ""
        num = abs(num)
        pos = int(math.log(num, 7))
        while(num>0):
            cur = int(num/(math.pow(7, pos)))
            output+=str(cur)
            num -= cur*(math.pow(7, pos))
            if pos>=1 and num==0:
                output+="0"*pos
            pos-=1
        return output if flag else "-"+output
