class Solution:
    def convertToTitle(self, num: int) -> str:
		# We make this lookup list, having A-Z in ascending order
        alpha = [chr(x) for x in range(ord("A"), ord("Z")+1)]     # range(65, 90+1) -> 91-65 = 26
        res = ""

        while num > 0:
            res += alpha[(num-1)%26]     # since 0 indexed list, num-1 % 26 gives the index of ch in alpha
            num = (num-1) // 26 
        return res[::-1]
