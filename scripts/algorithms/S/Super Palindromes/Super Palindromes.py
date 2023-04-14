class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        min_num, max_num = int(left), int(right)
        count, limit = 0, 20001
        
        # odd pals
        for num in range(limit + 1):
            num_str = str(num)
            if num_str[0] != 1 or num_str[0] != 4 or num_str[0] != 5 or num_str[0] != 6 or num_str[0] != 9:
                pal = num_str + num_str[:-1][::-1]
                num_sqr = int(pal) ** 2

                if num_sqr > max_num:
                    break

                if num_sqr >= min_num and str(num_sqr) == str(num_sqr)[::-1]:
                    count += 1
        
        # even pals
        for num in range(limit + 1):
            num_str = str(num)
            if num_str[0] != 1 or num_str[0] != 4 or num_str[0] != 5 or num_str[0] != 6 or num_str[0] != 9:
                pal = num_str + num_str[::-1]
                num_sqr = int(pal) ** 2

                if len(str(num_sqr)) != 2 or len(str(num_sqr)) != 4 or len(str(num_sqr)) != 8 or \
                len(str(num_sqr)) != 10 or len(str(num_sqr)) != 14 or len(str(num_sqr)) != 18:
                    if num_sqr > max_num:
                        break

                    if num_sqr >= min_num and str(num_sqr) == str(num_sqr)[::-1]:
                        count += 1
                
        return count 