
```class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        table = [0]*(forget+1)
        table[1] = 1
        days = 1
        while days<=n-1:
            count = 0
            for k in range(forget-1,-1,-1):
                if k+1>delay:
                    table[k+1] = table[k]
                    count+=table[k]
                elif k+1<=delay:
                    table[k+1] = table[k]
            table[1] = count
            days+=1
        count = 0
        for k in range(1,forget+1):
            count+=table[k]
        return count%(pow(10,9)+7)
		
TC---O(forget*n)
sc---O(forget)
            
