class Solution:
    def numberToWords(self, num: int) -> str:
        
        if num == 0:
            return "Zero"
        
        dic1 = {1000000000: "Billion", 1000000: "Million", 1000: "Thousand", 1: ""}
        dic2 = {90: "Ninety", 80: "Eighty", 70: "Seventy", 60: "Sixty", 50: "Fifty", 40: "Forty", 30: "Thirty", 20: "Twenty", 19: 'Nineteen', 18: "Eighteen", 17: "Seventeen", 16: "Sixteen", 15: "Fifteen", 14: "Fourteen", 13: "Thirteen", 12: "Twelve", 11: "Eleven", 10: "Ten", 9: "Nine", 8: "Eight", 7: "Seven", 6: "Six", 5: "Five", 4: "Four", 3: "Three", 2: "Two", 1: "One"}
        
        def construct_num(num):
            ans = ''
            d, num = divmod(num, 100)
            if d > 0:
                ans += dic2[d] + " " + "Hundred"
            for k, v in dic2.items():
                d, num = divmod(num, k)
                if d > 0:
                    ans += " " + v
            return ans.lstrip()                               
        
        ans = ""
        for k, v in dic1.items():
            d, num = divmod(num, k)
            if d > 0:
                ans += " " + construct_num(d) + " " + v
                
        return ans.strip()
