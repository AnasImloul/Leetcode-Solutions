class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        inventory.sort(reverse=True) 
        inventory += [0]
        res = 0
        k = 1
        
        for i in range(len(inventory)-1): 
            if inventory[i] > inventory[i+1]: 
                if k*(inventory[i]-inventory[i+1]) < orders:
                    diff = inventory[i]-inventory[i+1]
                    res += k*(inventory[i]+inventory[i+1]+1)*(diff)//2
                    orders -= k*diff
                else: 
                    q, r = divmod(orders, k)
                    res += k*(inventory[i]+(inventory[i]-q+1))*q//2
                    res += r*(inventory[i]-q)
                    return res%(10**9+7)
            k += 1
