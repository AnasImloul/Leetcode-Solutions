class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        n_to_list = list(str(n))
        
        sum_of_digits = 0 
        for num in n_to_list:
            sum_of_digits = sum_of_digits + int(num)
        
        product_of_digits = 1
        for num in n_to_list:
            product_of_digits = product_of_digits * int(num)
            
        answer = product_of_digits - sum_of_digits
        
        return answer
