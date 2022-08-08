class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        
        self.n = n 
        self.discount = discount 
        self.price = { }
        self.customer = 0 
        
        for i in range(len(products))  : 
            self.price[products[i]] = prices[i]

    def getBill(self, product: List[int], amount: List[int]) -> float:
        
        self.customer += 1
        
        bill = 0 
        
        for i in range(len(product)) : 
            bill += amount[i] * self.price[product[i]]
        
        
        if self.customer == self.n : 
            bill = bill * (1 - self.discount / 100)
            self.customer = 0 
            
            
        return bill
            
        


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
